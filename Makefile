# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 17:19:19 by alvalope          #+#    #+#              #
#    Updated: 2023/05/03 17:30:39 by alvalope         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

HEADER = ft_printf.h $(LIBFT_PATH)/libft.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIB = ar rcs

SRCS = ft_printf.c ft_put_all.c ft_put_unsigned.c ft_free_itoa.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(HEADER)
	cp $(LIBFT) $(NAME)
	$(LIB) $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re