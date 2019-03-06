# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/02 17:42:56 by mdelarbr     #+#   ##    ##    #+#        #
#    Updated: 2019/01/21 20:12:30 by mdelarbr    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c\
ft_bzero.c\
ft_count_word.c\
ft_get_word.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isblanc.c\
ft_isdigit.c\
ft_isprint.c\
ft_isspace.c\
ft_itoa.c\
ft_lstadd.c\
ft_lstdel.c\
ft_lstdelone.c\
ft_lstiter.c\
ft_lstmap.c\
ft_lstnew.c\
ft_memalloc.c\
ft_memccpy.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memdel.c\
ft_memmove.c\
ft_memset.c\
ft_putchar.c\
ft_putchar_fd.c\
ft_putendl.c\
ft_putendl_fd.c\
ft_putnbr.c\
ft_putnbr_fd.c\
ft_putstr.c\
ft_putstr_fd.c\
ft_str_space.c\
ft_strcat.c\
ft_strchr.c\
ft_strclr.c\
ft_strcmp.c\
ft_strcpy.c\
ft_strdel.c\
ft_strdup.c\
ft_strequ.c\
ft_striter.c\
ft_striteri.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlen.c\
ft_strmap.c\
ft_strmapi.c\
ft_strncat.c\
ft_strncmp.c\
ft_strncpy.c\
ft_strnequ.c\
ft_strnew.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strsplit.c\
ft_strstr.c\
ft_strsub.c\
ft_strtrim.c\
ft_tolower.c\
ft_toupper.c\
ft_strfjoin.c\
ft_strfsub.c\
ft_strclen.c\
ft_itoa_base.c\
ft_atoi_base.c\
ft_search.c\
str_search.c\
count_char.c\
ft_strintchr.c\

SRCO = $(SRC:.c=.o)
FLAG = -Wall -Werror -Wextra
HEADER = includes
OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME) : $(OBJ)
	@ar rc $@ $^
	@ranlib $@

OBJ:
	gcc -c $(FLAG) $(NAME) -I

clean:
	/bin/rm -rf $(SRCO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

