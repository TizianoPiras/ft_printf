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

NAME = libftprintf.a

HEADER = $(NAME:.a=.h)

SOURCES = ft_printf.c \
ft_printf_utils.c \
ft_printpoint.c \
ft_printunbr.c \
ft_printhex.c 

OBJECTS = $(SOURCES:.c=.o)

LIBC = ar rcs
LIBFT = libft/libft.a

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

all: $(LIBFT) $(NAME) 

${NAME}: $(OBJECTS)
		@cp $(LIBFT) ./$(NAME)
		@$(LIBC) $(NAME) $(OBJECTS) 
		@ranlib $(NAME)

.o:.c
		@$(CC) $(CFLAGS) $(OBJECTS) $< -o $(<:.c=.o) $(LIBFT)

$(LIBFT):
		@make -C libft

clean:
		@make clean -C libft
		@$(RM) $(OBJECTS)

fclean: clean
		@make fclean -C libft
		@$(RM) $(NAME)

re: fclean all
