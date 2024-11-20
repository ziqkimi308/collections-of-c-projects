# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhakimi- <mhakimi-@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 11:20:15 by mhakimi-          #+#    #+#              #
#    Updated: 2024/11/20 12:23:52 by mhakimi-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_atoi \
	ft_bzero \
	ft_calloc \
	ft_isalnum \
	ft_isalpha \
	ft_isascii \
	ft_isdigit \
	ft_isprint \
	ft_itoa \
	ft_memchr \
	ft_memcmp \
	ft_memcpy \
	ft_memmove \
	ft_memset \
	ft_putchar_fd \
	ft_putendl_fd \
	ft_putnbr_fd \
	ft_putstr_fd \
	ft_split \
	ft_strchr \
	ft_strdup \
	ft_striteri \
	ft_strjoin \
	ft_strlcat \
	ft_strlcpy \
	ft_strlen \
	ft_strmapi \
	ft_strncmp \
	ft_strnstr \
	ft_strrchr \
	ft_strtrim \
	ft_substr \
	ft_tolower \
	ft_toupper

BONUS_FILES = ft_lstnew \
	ft_lstadd_front \
	ft_lstadd_back \
	ft_lstdelone \
	ft_lstclear \
	ft_lstiter \
	ft_lstlast \
	ft_lstmap \
	ft_lstsize

COMPILER = cc
COMPILER_FLAGS = -Wall -Wextra -Werror

C_FILES	= $(FILES:%=%.c)
O_FILES	= $(FILES:%=%.o)
BONUS_C_FILES = $(BONUS_FILES:%=%.c)
BONUS_O_FILES = $(BONUS_FILES:%=%.o)

%.o: %.c
	$(COMPILER) $(COMPILER_FLAGS) -c $< -o $@

$(NAME): $(O_FILES)
	ar -rc $(NAME) $(O_FILES)
	ranlib $(NAME)

all: $(NAME)

bonus: $(NAME) $(BONUS_O_FILES)
	ar -rc $(NAME) $(O_FILES) $(BONUS_O_FILES)
	ranlib $(NAME)

clean:
	rm -f $(O_FILES) $(BONUS_O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

# so:
# 	$(COMPILER) -nostartfiles -fPIC $(COMPILER_FLAGS) $(C_FILES) -o libft.o
# 	cc -nostartfiles -shared -o libft.so $(O_FILES)
# soclean: fclean
# 	rm -f libft.o libft.so

.PHONY: all clean fclean re bonus
