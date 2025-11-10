# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 13:25:31 by hecalder          #+#    #+#              #
#    Updated: 2025/11/10 23:19:59 by hecalder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

#Source files and object files
SRC = ft_isalpha.c ft_toupper.c ft_tolower.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
      ft_isprint.c ft_strlen.c ft_strchr.c
OBJ = $(SRC:.c=.o)

#Output library
NAME = libft.a

#Targets
all: $(NAME)

$(NAME): $(OBJ)

	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
