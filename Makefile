# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 14:17:01 by pandalaf          #+#    #+#              #
#    Updated: 2022/10/28 19:26:16 by pandalaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target output
NAME := minitalk
EXECS := client server
BEXECS := client_bonus server_bonus
# Compiler options
CC := cc
CFLAGS := -Wall -Werror -Wextra
# Libft location
LIBFT := libft.a
LIBFT_PATH := libft/
LIBFT_FULL = $(addprefix $(LIBFT_PATH), $(LIBFT))
# Included source files
SRC_DIR := src/
C_SRC := client.c signals.c
S_SRC := server.c
C_SRC_FULL = $(addprefix $(SRC_DIR), $(C_SRC))
S_SRC_FULL = $(addprefix $(SRC_DIR), $(S_SRC))
# Included bonus source files
C_BSRC := client_bonus.c signals.c
S_BSRC := server_bonus.c
C_BSRC_FULL = $(addprefix $(SRC_DIR), $(C_BSRC))
S_BSRC_FULL = $(addprefix $(SRC_DIR), $(S_BSRC))

# Make desired targets
all: directories $(NAME)

# Make required directories
directories: $(OBJ_DIR)

# Make target executables
$(NAME): $(EXECS)

# Make bonus executables
bonus: $(BEXECS)

# Make the client executable
client: $(C_SRC_FULL) minitalk.h $(LIBFT_FULL)
	$(CC) $(CFLAGS) -o $@ $(C_SRC_FULL) $(LIBFT_FULL)

# Make the server executable
server: $(S_SRC_FULL) $(LIBFT_FULL)
	$(CC) $(CFLAGS) -o $@ $< $(LIBFT_FULL)

# Make the client executable
client_bonus: $(C_BSRC_FULL) minitalk.h $(LIBFT_FULL)
	$(CC) $(CFLAGS) -o $@ $(C_BSRC_FULL) $(LIBFT_FULL)

# Make the server executable
server_bonus: $(S_BSRC_FULL) $(LIBFT_FULL)
	$(CC) $(CFLAGS) -o $@ $< $(LIBFT_FULL)

# Make Libft archive
$(LIBFT_FULL): $(LIBFT_PATH)
	make -C $(LIBFT_PATH) all

# Make object files
$(addprefix $(OBJ_DIR), %.o): %.c | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $^ -o $@

# Make object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean intermediary files
clean:
	make -C $(LIBFT_PATH) clean

# Clean all non-source files
fclean: clean
	rm -f $(EXECS) $(BEXECS)
	make -C $(LIBFT_PATH) fclean

# Wipe all and make again
re: fclean all

# Make sure these aren't treated as files
.PHONY: all clean fclean re bonus directories
