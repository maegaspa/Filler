# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/05/27 14:55:34 by maegaspa     #+#   ##    ##    #+#        #
#    Updated: 2019/08/14 17:52:38 by maegaspa    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = maegaspa.filler

SRCS =  main.c \
		src/get_next_line.c \
		src/filler.c \
		src/parse.c \
		src/util.c \
		src/algo.c \
		src/aff.c

OBJ = $(SRCS:%.c=%.o)

HEADER = includes

CFLAGS = -Wall -Werror -Wextra -g

LIBFT = libft/libft.a

all: $(NAME)
	make -C libft

$(NAME): $(LIBFT) $(OBJ)
	gcc $(CFLAGS) $^ -o $@

%.o : %.c includes/filler.h
	gcc -Wall -Werror -Wextra -g -c $< -o $@

$(LIBFT):
	make -C libft/

clean:
	make clean -C libft/
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all

norm:
	norminette src/*.c $(HEADER)/*.h libft/*.c
