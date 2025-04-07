NAME = fractol

SRC = 	exit_utils.c	\
	init.c		\
	input_parser.c	\
	main.c		\
	math_utils.c	\
	render.c	\
	str_utils.c	\
	events.c	\
	ft_atoi.c	\
	define_fractal.c
SRC_DIR = src/

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

CC = cc
CCFLAGS = -Wextra -Werror -Wall
DEBUG = -g 

MLX_DIR = mlx/
MLX_LIB = $(MLX_DIR)libmlx_Linux.a
MLX_INC = -I$(MLX_DIR)
MLX_LINK = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES = -Iincludes $(MLX_INC)

all: $(NAME)

$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(CCFLAGS) $(DEBUG) $(OBJ) $(MLX_LINK) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CCFLAGS) $(DEBUG) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
