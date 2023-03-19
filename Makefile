NAME = fdf

SRCS = src/main.c \
	   src/draw_line.c \
	   src/fdf_utils.c \
	   src/window.c \
	   src/validate.c \
	   src/checkers.c \
	   src/process_data.c \
	   src/plot.c

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
