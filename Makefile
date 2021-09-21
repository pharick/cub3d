NAME		= cub3D

CC			= gcc
AR			= ar rc
RM			= rm -f

_SRCS		= main.c config.c parse_map.c texture.c render.c dda.c \
			  keys.c move.c clean.c sprites.c render_sprites.c \
			  bitmap.c errors.c
SRCS		= $(addprefix srcs/, $(_SRCS))

OBJS		= $(SRCS:.c=.o)

CFLAGS		= -Wall -Wextra -Werror

%.o: %.c
			$(CC) $(CFLAGS) -Iincludes -Ilibft -Imlx -c $< -o $@

$(NAME):	$(OBJS)
			make -C libft
			make -C mlx
			mv mlx/libmlx.dylib libmlx.dylib
			$(CC) -Llibft -lft -L. -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

all:		$(NAME)

.PHONY: clean fclean re all
