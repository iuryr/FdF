NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror -c
FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
OTHER_LIBS = -lX11 -lXext -lmlx -lm

SRC_FILES = main.c \
			init.c \
			draw.c \
			draw_utils.c \
			render.c \
			keys.c \
			geometry.c \
			geometry_utils.c \
			00_parsemap.c \
			00_parsemap_utils.c \
			01_load_points.c \
			01_load_points_utils.c \
			02_projection.c \
			graphic_cleanup_utils.c

BRES_FILES = bres_test.c \
			 init.c \
			 draw.c \
			 draw_utils.c \
			 render.c \
			 keys.c \
			 geometry.c \
			 00_parsemap.c \
			 00_parsemap_utils.c \
			 01_load_points.c \
			 02_projection.c

OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(FLAGS) $(OBJ_FILES) -o $(NAME) $(OTHER_LIBS) -Llibft -l:libft.a

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

#########Regras de teste
compile_gdb:
	$(CC) $(FLAGS) $(SRC_FILES) libft/*.c -gdwarf-4 -o test.out $(OTHER_LIBS) -Llibft -l:libft.a

test: compile_gdb
	gdb --args test.out maps/test_maps/42.fdf

leak: compile_gdb
	valgrind --leak-check=full --show-leak-kinds=all ./test.out maps/test_maps/42.fdf

######### Testando algoritmo de bresenham
compile_bres:
	$(CC) $(FLAGS) $(BRES_FILES) libft/*.c -gdwarf-4 -o test.out $(OTHER_LIBS) -Llibft -l:libft.a

bresenham: compile_bres
	./test.out
