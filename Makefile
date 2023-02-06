# So_long Makefile

NAME = so_long

# My libft.a
LIBFT_PATH = ./libs/libft
LIBFT_HEADER = $(LIBFT_PATH)/src/lift.h
LIBFT = $(LIBFT_PATH)/libft.a

# MLX
MLX_PATH = ./libs/minilibx
MLX_HEADER = $(MLX_PATH)/mlx.h
MLX = $(MLX_PATH)/libmlx.a

# Paths
SRCS_PATH = ./src
OBJS_PATH = ./objs

#Headers so_long
HEADER = ./headers

# Files
SRCS_FILES = so_long.c 0-error_functions.c 1-input.c 2-map.c 3-check_map.c 4-game_init.c 5-sprites.c \
			6-hooks.c 7-clean.c

# all files .c with the path
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_FILES)) 

# all files .o
OBJS = $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)

# Compilation
CC = cc
DEBUG = -g
CFLAGS = -Wall -Wextra -Werror $(DEBUG)
GNL_FLAGS =	-D BUFFER_SIZE=10
LIB_FLAGS = -lft -lmlx -lXext -lX11
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck

# Clean
RM 		= rm -f
RM_DIR	= rm -rf

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(OBJS) -L$(LIBFT_PATH) -L$(MLX_PATH) $(LIB_FLAGS) -o $(NAME)

# gerar os arquivos .o
$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	@mkdir -p $(OBJS_PATH)
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH)
	@echo "libft.a created"

$(MLX):
	@make -C $(MLX_PATH)
	@echo "libmlx.a created"

valgrind: $(NAME)
	$(VALGRIND) $(NAME) $(MAP)

clean:
	@$(RM_DIR) $(OBJS_PATH)

fclean:	clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
