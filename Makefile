NAME = mouse_jiggler

SRC =	./main.c \

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	gcc -o $(NAME) $(SRC) -lX11

clean:
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re: fclean all
