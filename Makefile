NAME = fdf

SRCS = main.c draw_line.c fdf_utils.c window.c validate.c checkers.c process_data.c plot.c

OBJS = $(SRCS:.c=.o)

LIBS = libft/libft.a

CC = cc

%.o: %.c
	$(CC) -g -Wall -Wextra -Werror -Imlx -c $< -o $@

MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(OBJS) $(LIBS) $(MLXFLAGS)  -o  $(NAME)

$(LIBS): libft/ mlx/
	make -C libft/ all
	make -C mlx/ all

clean:
	rm -rf *.o libft/*.o mlx/*o

fclean:
	rm -rf *.o libft/*.o mlx/*o fdf libft/libft.a

re: fclean all

.PHONY:		all clean fclean re
