# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g -O0
RELEASE_FLAGS = -O2
INCLUDES = -I$(LIBFT_DIR) -I$(UNITY_DIR) -I.

# Directories
LIBFT_DIR = ../Libft
UNITY_DIR = unity
OBJ_DIR = obj
BONUS_OBJ_DIR = obj_bonus

# Files
TEST_SRC = test_libft.c
TEST_OBJ = $(addprefix $(OBJ_DIR)/, $(TEST_SRC:.c=.o))
BONUS_TEST_OBJ = $(addprefix $(BONUS_OBJ_DIR)/, $(TEST_SRC:.c=.o))
TEST_NAME = test_libft
BONUS_TEST_NAME = test_libft_bonus

# Unity framework files
UNITY_SRC = $(UNITY_DIR)/unity.c
UNITY_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(UNITY_SRC:.c=.o)))
BONUS_UNITY_OBJ = $(addprefix $(BONUS_OBJ_DIR)/, $(notdir $(UNITY_SRC:.c=.o)))

# Library
LIBFT = $(LIBFT_DIR)/libft.a

# Colors for terminal output
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
BOLD = \033[1m
NC = \033[0m # No Color

# Create object directories
$(shell mkdir -p $(OBJ_DIR) $(BONUS_OBJ_DIR))

# Rules
all: $(TEST_NAME)

$(TEST_NAME): $(TEST_OBJ) $(UNITY_OBJ) $(LIBFT)
	@echo "$(BOLD)$(BLUE)Building mandatory test executable...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(TEST_OBJ) $(UNITY_OBJ) -L$(LIBFT_DIR) -lft -o $(TEST_NAME)
	@echo "$(BOLD)$(GREEN)✓ Mandatory test executable built successfully!$(NC)"

$(BONUS_TEST_NAME): $(BONUS_TEST_OBJ) $(BONUS_UNITY_OBJ) $(LIBFT)
	@echo "$(BOLD)$(BLUE)Building bonus test executable...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_TEST_OBJ) $(BONUS_UNITY_OBJ) -L$(LIBFT_DIR) -lft -o $(BONUS_TEST_NAME)
	@echo "$(BOLD)$(GREEN)✓ Bonus test executable built successfully!$(NC)"

# Compile test_libft.c for mandatory tests
$(OBJ_DIR)/%.o: %.c
	@echo "$(CYAN)Compiling $< for mandatory tests...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile test_libft.c for bonus tests
$(BONUS_OBJ_DIR)/%.o: %.c
	@echo "$(CYAN)Compiling $< for bonus tests...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -DBONUS -c $< -o $@

# Compile Unity framework for mandatory tests
$(OBJ_DIR)/%.o: $(UNITY_DIR)/%.c
	@echo "$(CYAN)Compiling $< for mandatory tests...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile Unity framework for bonus tests
$(BONUS_OBJ_DIR)/%.o: $(UNITY_DIR)/%.c
	@echo "$(CYAN)Compiling $< for bonus tests...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -DBONUS -c $< -o $@

$(LIBFT):
	@echo "$(BOLD)$(BLUE)Building libft...$(NC)"
	@$(MAKE) -C $(LIBFT_DIR) bonus
	@echo "$(BOLD)$(GREEN)✓ libft built successfully!$(NC)"

# Testing
test: $(TEST_NAME)
	@echo "\n$(BOLD)$(MAGENTA)=== Running Mandatory Tests ===$(NC)"
	@echo "$(BOLD)$(BLUE)Running tests with memory leak check...$(NC)\n"
	@leaks --atExit -- ./$(TEST_NAME) | sed 's/^/  /'

bonus: $(BONUS_TEST_NAME)
	@echo "\n$(BOLD)$(MAGENTA)=== Running All Tests (Mandatory + Bonus) ===$(NC)"
	@echo "$(BOLD)$(BLUE)Running tests with memory leak check...$(NC)\n"
	@leaks --atExit -- ./$(BONUS_TEST_NAME) | sed 's/^/  /'

# Cleanup
clean:
	@echo "$(BOLD)$(YELLOW)Cleaning object files...$(NC)"
	@rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@echo "$(BOLD)$(GREEN)✓ Clean complete!$(NC)"

fclean: clean
	@echo "$(BOLD)$(YELLOW)Removing executables...$(NC)"
	@rm -f $(TEST_NAME) $(BONUS_TEST_NAME)
	@echo "$(BOLD)$(GREEN)✓ Fclean complete!$(NC)"

re: fclean all

.PHONY: all clean fclean re test bonus docs

docs:
	@echo "Generating documentation with Doxygen..."
	doxygen Doxyfile
	@echo "Documentation generated in docs/html/index.html"
	@if command -v open >/dev/null 2>&1; then \
		open docs/html/index.html; \
	elif command -v xdg-open >/dev/null 2>&1; then \
		xdg-open docs/html/index.html; \
	else \
		echo "Please open docs/html/index.html manually."; \
	fi 