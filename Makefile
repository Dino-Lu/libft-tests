# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g -O0
RELEASE_FLAGS = -O2

# Directories
LIBFT_DIR = ../Libft
UNITY_DIR = unity
OBJ_DIR = obj

# Files
TEST_SRC = test_libft.c
TEST_OBJ = $(addprefix $(OBJ_DIR)/, $(TEST_SRC:.c=.o))
TEST_NAME = test_libft

# Unity framework files
UNITY_SRC = $(UNITY_DIR)/unity.c
UNITY_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(UNITY_SRC:.c=.o)))

# Library
LIBFT = $(LIBFT_DIR)/libft.a

# Colors for terminal output
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
NC = \033[0m # No Color

# Create object directory
$(shell mkdir -p $(OBJ_DIR))

# Rules
all: $(TEST_NAME)

$(TEST_NAME): $(TEST_OBJ) $(UNITY_OBJ) $(LIBFT)
	@echo "$(YELLOW)Building test executable...$(NC)"
	@$(CC) $(CFLAGS) $(TEST_OBJ) $(UNITY_OBJ) -L$(LIBFT_DIR) -lft -o $(TEST_NAME)
	@echo "$(GREEN)Test executable built successfully!$(NC)"

$(OBJ_DIR)/%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(UNITY_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(UNITY_DIR)/%.c
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -I$(UNITY_DIR) -c $< -o $@

$(LIBFT):
	@echo "$(YELLOW)Building libft...$(NC)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)libft built successfully!$(NC)"

# Testing
test: $(TEST_NAME)
	@echo "$(YELLOW)Running tests...$(NC)"
	@./$(TEST_NAME)

# Debug build
debug: CFLAGS += $(DEBUG_FLAGS)
debug: fclean all

# Release build
release: CFLAGS += $(RELEASE_FLAGS)
release: fclean all

# Cleanup
clean:
	@echo "$(YELLOW)Cleaning object files...$(NC)"
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Clean complete!$(NC)"

fclean: clean
	@echo "$(YELLOW)Removing executable...$(NC)"
	@rm -f $(TEST_NAME)
	@echo "$(GREEN)Fclean complete!$(NC)"

re: fclean all

# Help
help:
	@echo "$(YELLOW)Available targets:$(NC)"
	@echo "  all      - Build the test executable"
	@echo "  test     - Run the tests"
	@echo "  debug    - Build with debug flags"
	@echo "  release  - Build with optimization flags"
	@echo "  clean    - Remove object files"
	@echo "  fclean   - Remove all generated files"
	@echo "  re       - Rebuild everything"
	@echo "  help     - Show this help message"

.PHONY: all clean fclean re test debug release help 