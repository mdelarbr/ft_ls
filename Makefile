# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/22 10:56:25 by mdelarbr     #+#   ##    ##    #+#        #
#    Updated: 2019/02/06 15:33:21 by mdelarbr    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = ft_ls

FLAGS = -Wall -Wextra -Werror -g

SRC =	srcs/ft_ls.c\
		srcs/option.c\
		srcs/struct.c\
		srcs/file.c\
		srcs/sort.c\
		srcs/display_acl.c\
		srcs/display.c\
		srcs/folder.c\
		srcs/init_bis.c\
		srcs/sort_size.c\
		srcs/init.c\
		srcs/display_bis.c\
		srcs/display_long.c\
		srcs/display_space.c\
		srcs/display_option.c\
		srcs/folder_name.c
OBJ = $(subst .c,.o,$(SRC))

LIGHT_PINK = \033[0;38;5;200m

PINK = \033[0;38;5;198m

DARK_BLUE = \033[0;38;5;110m

GREEN = \033[0;38;5;111m

LIGHT_GREEN = \033[0;38;5;121m

FLASH_GREEN = \033[33;32m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(DARK_BLUE)\nFichiers de "$(NAME)" compilés\n"
	@echo "$(LIGHT_GREEN)Compilation libft : "
	@make -C libft/
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -I libft/includes -L libft/ -lft
	@echo "$(FLASH_GREEN)Programme "$(NAME)" compilé et prêt à l'usage !\n"

%.o: %.c fillit.h
	@gcc $(FLAGS) -I libft/includes -o $@ -c $<
	@echo "$(DARK_BLUE).\c"

clean:
	@rm -rf $(OBJ)
	@make -C libft/ clean
	@echo "$(LIGHT_PINK)Suppression des .o de "$(NAME)"\n"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft/ fclean
	@echo "$(PINK)Suppression de" $(NAME)"\n"

re: fclean all
