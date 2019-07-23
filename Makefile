# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/05/27 14:55:34 by maegaspa     #+#   ##    ##    #+#        #
#    Updated: 2019/07/23 15:21:32 by maegaspa    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = maegaspa.filler
CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDE = /includes/filler.h

FILES = src/filler\
		src/parse\
		src/get_next_line\
		src/util\
		src/algo\

SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "----------------------------------------"
	@echo "\nGARROT LA MOUILLE se met au trabajo"
	@echo "\n----------------------------------------"
	@make -C libft/
	@cp libft/libft.a ./$(NAME)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@echo "----------------------------------------"
	@echo "\nGARROT LA MOUILLE NETTOIE CE GENRE DE .o"
	@echo "\n----------------------------------------"
	@rm -f $(OBJ)
	@make clean -C libft/

fclean: clean
	@echo "--------------------------------------------"
	@echo "\n    - GARROT NETTOIE TOUT WOLA HADIN -"
	@echo "\n--------------------------------------------"
	@rm -f $(NAME)
	@rm -f libft/libft.a

re: fclean all