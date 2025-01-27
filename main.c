#include <X11/Xlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Open the X display
    Display *display = XOpenDisplay(NULL);
    if (!display) {
        fprintf(stderr, "Unable to open X display. Make sure X server is running.\n");
        return 1;
    }

    // Get the root window for the default screen
    Window root = DefaultRootWindow(display);
    if (!root) {
        fprintf(stderr, "Failed to get the root window.\n");
        XCloseDisplay(display);
        return 1;
    }

    // Get the screen dimensions
    int screen = DefaultScreen(display);
    int screen_width = DisplayWidth(display, screen);
    int screen_height = DisplayHeight(display, screen);

    // Seed the random number generator
    srand(time(NULL));

    printf("Mouse jiggler started. Press Ctrl+C to stop.\n");

    while (1) {
        // Get the current pointer position
        int x = 0, y = 0;
        Window dummy_window;
        int dummy;
        unsigned int dummy_ui;

        if (XQueryPointer(display, root, &dummy_window, &dummy_window, &x, &y, &dummy, &dummy, &dummy_ui)) {
            // Generate small random movements
            int new_x = x + (rand() % 11 - 5); // Move between -5 and +5 pixels
            int new_y = y + (rand() % 11 - 5);

            // Ensure the new position stays within the screen bounds
            if (new_x < 0) new_x = 0;
            if (new_y < 0) new_y = 0;
            if (new_x >= screen_width) new_x = screen_width - 1;
            if (new_y >= screen_height) new_y = screen_height - 1;

            // Move the pointer
            XWarpPointer(display, None, root, 0, 0, 0, 0, new_x, new_y);
            XFlush(display);
        } else {
            fprintf(stderr, "Failed to query pointer position. Exiting.\n");
            break;
        }

        // Wait for 2 minutes
        sleep(120);
    }

    // Clean up
    XCloseDisplay(display);
    return 0;
}

