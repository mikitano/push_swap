NAME = push_swap
EXEC = $(BIN_DIR)/$(NAME)

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include
LIBFT_DIR = libftx
LIBFT = $(LIBFT_DIR)/libft.a

SRC_FILES = main.c \
	node_initi_create_detach.c \
	node_push_and_insert.c \
	node_delete_and_clear.c \
	swap_operations.c \
	push_operations.c \
	rotate_operations.c \
	rrotate_operations.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o)) 
HEADERS = $(addprefix $(INCLUDE_DIR)/, push_swap.h)

CC = cc
AR = ar
ARFLAGS = crs

CCFLAGS = -Wall -Wextra -Werror
IFLAGS = -I $(INCLUDE_DIR) -I $(LIBFT_DIR)/include
LDFLAGS = -L $(LIBFT_DIR) -lft

RM = rm
RMFLAGS = -rf

all: $(EXEC)

$(EXEC) : $(OBJS) $(LIBFT)
		@mkdir -p $(BIN_DIR)
		@$(CC) $(CCFLAGS) $(OBJS) $(LDFLAGS) -o $(EXEC)
		@echo "[\033[0;32mOK\033[0m] $(NAME) COMPILED in $(BIN_DIR)/!"

$(LIBFT) :
		@echo "[\033[0;33m...\033[0m] CREATING libft..."
		@$(MAKE) -C $(LIBFT_DIR) --silent

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADERS)
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CCFLAGS) $(IFLAGS) -c $< -o $@
		@echo "[\033[0;32mOK\033[0m] COMPILED $<"

clean :
		@$(RM) $(RMFLAGS) $(OBJ_DIR)
		@$(MAKE) -C $(LIBFT_DIR) clean --silent
		@echo "[\033[0;32mOK\033[0m] CLEAR files!"

fclean : clean
		@$(RM) $(RMFLAGS) $(BIN_DIR)
		@$(MAKE) -C $(LIBFT_DIR) fclean --silent
		@echo "[\033[0;32mOK\033[0m] ALL CLEAR!"

re : fclean all
		$(info Project REBUILD!)

.PHONY: all clean fclean re
