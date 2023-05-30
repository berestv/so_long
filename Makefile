NAME = so_long.a

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

LIBFT = libft/libft.a

SRCS =  so_long.c


BONUS = \

OBJS = $(SRCS:%.c=%.o)

OBJS_BONUS = $(BONUS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o so_long

bonus: $(OBJS_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o bonus

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_BONUS)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME) push_swap
	@$(RM) $(NAME) checker

re: fclean all