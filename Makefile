NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -lX11 -lXext
RM = rm -rf

LIBFT = libft/libft.a
MLX = ./minilibx-linux/libmlx_Linux.a

SRCS = 	so_long.c\
		utils.c\
		utils2.c\
		errors.c\
		verif.c\
		map_ops.c\
		imgs_init.c\
		sprites.c\
		moves.c\

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(MLX):
	@$(MAKE) -C ./minilibx-linux


$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MFLAGS) -o $(NAME)

bonus: $(OBJS_BONUS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX) $(MFLAGS) -o $(NAME_BONUS)

clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(OBJS)
	@$(RM) $(NAME)

clean_bonus:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(OBJS_BONUS)
	@$(RM) $(NAME_BONUS)

fclean: clean clean_bonus
	@$(MAKE) fclean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)

re: fclean all