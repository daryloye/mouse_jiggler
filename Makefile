# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daong <daong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/27 09:24:53 by daong             #+#    #+#              #
#    Updated: 2024/10/27 09:24:53 by daong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
