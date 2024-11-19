# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhakimi- <mhakimi-@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 19:18:12 by mhakimi-          #+#    #+#              #
#    Updated: 2024/11/19 13:03:14 by mhakimi-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

FILES_C	= ft_printf.c ft_putaddr.c ft_putchar.c ft_putnbr_base.c \
			ft_putnbr_unsigned.c ft_putnbr.c ft_putstr.c

FILES_O	= ft_printf.o ft_putaddr.o ft_putchar.o ft_putnbr_base.o \
			ft_putnbr_unsigned.o ft_putnbr.o ft_putstr.o

COMPILER	= cc

FLAGS	= -Wall -Wextra -Werror

%.o : %.c
	$(COMPILER) $(FLAGS) -c $< -o $@

$(NAME): $(FILES_O)
	ar -rc $(NAME) $(FILES_O)

all: $(NAME)

bonus: all

clean:
	rm -f $(FILES_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re