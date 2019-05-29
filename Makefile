# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/05/27 14:55:34 by maegaspa     #+#   ##    ##    #+#        #
#    Updated: 2019/05/27 18:33:54 by maegaspa    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = maegaspa.filler
OBJ = maegaspa.filler
CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDE = ./includes

FILES = main\
		filler\

SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILEs))

all: $(NAME)

$(NAME): $(SRC) $(INCLUDE)
	@echo "-------------------- COMPILATION --------------------"
	@$(MAKE) -C libft/
	@$(CC) $(FLAGS) -o $(NAME) $(SRC) -I$(INCLUDE) -L libft/ -libft

clean:
	@echo "----------------------------------------"
	@echo "\nGARROT LA MOUILLE NETTOIE CE GENRE DE .o"
	@echo "\n----------------------------------------"
	@rm -f $(OBJ)
	@$(MAKE) -C libft/ clean

fclean: clean
	@echo "--------------------------------------------"
	@echo "\n    - GARROT NETTOIE TOUT WOLA HADIN -"
	@echo "\n--------------------------------------------"
	@rm -f $(NAME)
	@rm -f libft/libft.a

re: fclean all