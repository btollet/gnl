# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/18 13:08:36 by benjamin          #+#    #+#              #
#    Updated: 2016/12/23 17:53:19 by benjamin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c       ft_lstdelone.c  ft_putchar.c    ft_strdel.c \
ft_bzero.c      ft_lstiter.c    ft_putchar_fd.c ft_strdup.c     ft_strnew.c \
ft_intlen.c     ft_lstlen.c     ft_putendl.c    ft_strequ.c     ft_strnstr.c \
ft_isalnum.c    ft_lstmap.c     ft_putendl_fd.c ft_striter.c    ft_strrchr.c \
ft_isalpha.c    ft_lstnew.c     ft_putnbr.c     ft_striteri.c   ft_strsplit.c \
ft_isascii.c    ft_memalloc.c   ft_putnbr_fd.c  ft_strjoin.c    ft_wordcount.c \
ft_isblank.c    ft_memccpy.c    ft_putstr.c     ft_strlcat.c    ft_strsub.c \
ft_isdigit.c    ft_memchr.c     ft_putstr_fd.c  ft_strlen.c     ft_strtrim.c \
ft_isprint.c    ft_memcmp.c     ft_strcat.c     ft_strmap.c     ft_tolower.c \
ft_isxdigit.c   ft_memcpy.c     ft_strchr.c     ft_strmapi.c    ft_toupper.c \
ft_itoa.c       ft_memdel.c     ft_strclr.c     ft_strncat.c    ft_strstr.c \
ft_lstadd.c     ft_memmove.c    ft_strcmp.c     ft_strncmp.c    ft_wordlen.c \
ft_lstdel.c     ft_memset.c     ft_strcpy.c     ft_strncpy.c    ft_strnequ.c \

OBJ = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCS)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
