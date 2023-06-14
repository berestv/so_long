NAME = so_long.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MFLAGS =  -lX11 -lXext
RM = rm -rf

LIBFT = libft/libft.a
MLBX = minilibx-linux/libmlx_Linux.a

SRCS =  so_long.c \
		utils.c \
		errors.c \
		verif.c \

# BONUS = \

OBJS = $(SRCS:%.c=%.o)

OBJS_BONUS = $(BONUS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	make all -C libft
	make all -C minilibx-linux
	@$(CC) $(CFLAGS) $(MFLAGS) $(OBJS) $(LIBFT) $(MLBX) -o so_long

#bonus: $(OBJS_BONUS) $(MLBX) $(LIBFT)
#	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MFLAGS) -o bonus

clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_BONUS)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME) so_long
	@$(RM) $(NAME) bonus

re: fclean all