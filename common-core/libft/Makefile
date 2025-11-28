# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hecalder <hecalder@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 13:25:31 by hecalder          #+#    #+#              #
#    Updated: 2025/11/28 16:41:13 by hecalder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = src
CORE_DIR = $(SRC_DIR)/core
MEMORY_DIR = $(SRC_DIR)/memory
STRING_DIR = $(SRC_DIR)/string
LIST_DIR = $(SRC_DIR)/list
INC_DIR = include

# Source files (full paths)
SRC = $(CORE_DIR)/ft_atoi.c $(CORE_DIR)/ft_isalnum.c $(CORE_DIR)/ft_isalpha.c \
	  $(CORE_DIR)/ft_isascii.c $(CORE_DIR)/ft_isdigit.c $(CORE_DIR)/ft_isprint.c \
	  $(CORE_DIR)/ft_putchar_fd.c $(CORE_DIR)/ft_putendl_fd.c \
	  $(CORE_DIR)/ft_putnbr_fd.c $(CORE_DIR)/ft_putstr_fd.c \
	  $(CORE_DIR)/ft_tolower.c $(CORE_DIR)/ft_toupper.c \
	  $(MEMORY_DIR)/ft_bzero.c $(MEMORY_DIR)/ft_calloc.c $(MEMORY_DIR)/ft_memchr.c \
	  $(MEMORY_DIR)/ft_memcmp.c $(MEMORY_DIR)/ft_memcpy.c $(MEMORY_DIR)/ft_memmove.c \
	  $(MEMORY_DIR)/ft_memset.c \
	  $(STRING_DIR)/ft_itoa.c $(STRING_DIR)/ft_split.c $(STRING_DIR)/ft_strchr.c \
	  $(STRING_DIR)/ft_strdup.c $(STRING_DIR)/ft_striteri.c $(STRING_DIR)/ft_strjoin.c \
	  $(STRING_DIR)/ft_strlcat.c $(STRING_DIR)/ft_strlcpy.c $(STRING_DIR)/ft_strlen.c \
	  $(STRING_DIR)/ft_strmapi.c $(STRING_DIR)/ft_strncmp.c $(STRING_DIR)/ft_strnstr.c \
	  $(STRING_DIR)/ft_strrchr.c $(STRING_DIR)/ft_strtrim.c $(STRING_DIR)/ft_substr.c

# Bonus files
BONUS = $(LIST_DIR)/ft_lstadd_back.c $(LIST_DIR)/ft_lstadd_front.c $(LIST_DIR)/ft_lstclear.c \
		$(LIST_DIR)/ft_lstdelone.c $(LIST_DIR)/ft_lstiter.c $(LIST_DIR)/ft_lstlast.c \
		$(LIST_DIR)/ft_lstmap.c $(LIST_DIR)/ft_lstnew.c $(LIST_DIR)/ft_lstsize.c

# Object files (same folder, .c → .o)
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

# Output library
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUS_OBJ)
	ar -rcs $(NAME) $(OBJ) $(BONUS_OBJ)

# Generic compile rule for ANY folder
%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
