# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 14:17:01 by pandalaf          #+#    #+#              #
#    Updated: 2022/10/24 22:47:21 by pandalaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target output
NAME := client server
#BNAME := client_bonus server_bonus
# Compiler options
CC := cc
CFLAGS := -Wall -Werror -Wextra
# Libft location
LIBFT := libft.a
LIBFT_PATH := libft/
# Included source files
SRC_DIR := src/
SRC_S := client.c server.c
#BSRC
SRCS = $(addprefix $(SRC_DIR), $(SRC_S))
#BSRC
# Object files
OBJ_DIR = obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

# Make desired targets
all: directories $(NAME)

# Make required directories
directories: $(OBJ_DIR)

# Make target archive
$(NAME): $(OBJS) $(addprefix $(LIBFT_PATH), $(LIBFT))
	ar -rcs $@ $^

# Make Libft archive
$(addprefix $(LIBFT_PATH), $(LIBFT)): $(LIBFT_PATH)
	make -C $(LIBFT_PATH) all

# Make object files
$(addprefix $(OBJ_DIR), %.o): %.c | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $^ -o $@

# Make object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean intermediary files
clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_PATH) clean

# Clean all non-source files
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

# Wipe all and make again
re: fclean all

# Make sure these aren't treated as files
.PHONY: all clean fclean re bonus directories
