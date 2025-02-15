# Source files
SRC = SRC/ft_strlen.c SRC/ft_strncmp.c SRC/ft_strjoin.c SRC/ft_bzero.c \
	SRC/ft_strlcpy.c SRC/ft_strdup.c SRC/ft_putstr_fd.c SRC/ft_memset.c \
    SRC/ft_split.c SRC/ft_split_shell.c SRC/ft_split_shell_utils.c \
	SRC/get_next_line.c SRC/get_next_line_utils.c SRC/ft_strlcat.c

# Object files
OBJS = $(SRC:%.c=%.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Library name
NAME = libft.a

# Archive command
AR = ar rcs

# ANSI color codes
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RED = \033[0;31m
NC = \033[0m  # No Color (reset)

# Targets
$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(YELLOW)Creating static library: $(NAME)$(NC)"
	@echo "$(GREEN)SRC files are compiled and library is ready.$(NC)"

all: $(NAME)

$(OBJS): %.o: %.c
	@echo "$(BLUE)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJBONUS): %.o: %.c
	@echo "$(BLUE)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning up object files...$(NC)"
	@ rm -rf $(OBJS)

fclean: clean
	@echo "$(RED)Removing static library: $(NAME)$(NC)"
	@ rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re