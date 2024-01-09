NAME = fractol

CC = gcc

# if you want best performance you can add -O3 in CFLAGS (write warning are normals)

CFLAGS = -Wall -g -Werror -Wextra
#CFLAGS = -O3
LIBS = -lmlx_Linux -lXext -lX11 -lm

MLX = ./mlx

SRCS = main.c colors.c julia.c mandelbrot.c burningship.c riemann_zeta.c riemann_utils.c utils.c hooks.c maps.c fractals_inits.c print_fractal.c

OBJS = $(SRCS:.c=.o)

all: $(MLX) $(NAME)

$(MLX):
	@$(MAKE) -C $(MLX_SUBDIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) -I ./mlx -L ./mlx $(OBJS)  $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME)

re : fclean all

all: $(NAME)

.PHONY: clean fclean re all