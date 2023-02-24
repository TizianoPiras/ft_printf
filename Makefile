# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpiras <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 14:09:36 by tpiras            #+#    #+#              #
#    Updated: 2023/02/24 14:17:34 by tpiras           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

HEADER = $(NAME:.a=.h)

SOURCES = ./libft/ft_isalpha.c \
./libft/ft_isdigit.c \
./libft/ft_isalnum.c \
./libft/ft_isascii.c \
./libft/ft_isprint.c \
./libft/ft_strlen.c \
./libft/ft_memset.c \
./libft/ft_bzero.c \
./libft/ft_memcpy.c \
./libft/ft_memmove.c \
./libft/ft_strlcpy.c \
./libft/ft_strlcat.c \
./libft/ft_toupper.c \
./libft/ft_tolower.c \
./libft/ft_strchr.c \
./libft/ft_strrchr.c \
./libft/ft_strncmp.c \
./libft/ft_memchr.c \
./libft/ft_memcmp.c \
./libft/ft_strnstr.c \
./libft/ft_atoi.c \
./libft/ft_calloc.c \
./libft/ft_strdup.c \
./libft/ft_substr.c \
./libft/ft_strjoin.c \
./libft/ft_strtrim.c \
./libft/ft_split.c \
./libft/ft_itoa.c \
./libft/ft_strmapi.c \
./libft/ft_striteri.c \
./libft/ft_putchar_fd.c \
./libft/ft_putstr_fd.c \
./libft/ft_putendl_fd.c \
./libft/ft_putnbr_fd.c \

SOURCES_BONUS = ./libft/ft_lstnew.c \
./libft/ft_lstadd_front.c \
./libft/ft_lstsize.c \
./libft/ft_lstlast.c \
./libft/ft_lstadd_back.c \
./libft/ft_lstdelone.c \
./libft/ft_lstclear.c \
./libft/ft_lstiter.c \
./libft/ft_lstmap.c \

OBJECTS = $(SOURCES:.c=.o)

OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

LIBC = ar rcs

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

.o:.c
        $(CC) $(CFLAGS) $(OBJECTS) $< -o $(<:.c=.o)

${NAME}: $(OBJECTS)
        $(LIBC) $(NAME) $(OBJECTS)
        ranlib $(NAME)

all: $(NAME)

clean:
        $(RM) $(OBJECTS)

fclean: clean
        $(RM) $(NAME)

re: fclean all

bonus: $(OBJECTS) $(OBJECTS_BONUS)
    $(LIBC) $(NAME) $(OBJECTS) $(OBJECTS_BONUS)
    ranlib $(NAME)