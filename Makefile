NAME = fdf
BONUS = fdf_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -c
FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a


LIBS = -lX11 -lXext -lmlx -lm -L./libft -l:libft.a

SRC_FILES = main.c \
			00_parsemap_1.c \
			00_parsemap_2.c \
			01_load_points_1.c \
			01_load_points_2.c \
			01_load_points_3.c \
			02_init_1.c \
			03_render_1.c \
			04_geometry_1.c \
			04_geometry_2.c \
			05_projection_1.c \
			06_draw_1.c \
			06_draw_2.c \
			07_keys_1.c \
			08_graphic_cleanup_1.c

BONUS_SRC_FILES = main_bonus.c \
			00_parsemap_1_bonus.c \
			00_parsemap_2_bonus.c \
			01_load_points_1_bonus.c \
			01_load_points_2_bonus.c \
			01_load_points_3_bonus.c \
			02_init_1_bonus.c \
			03_render_1_bonus.c \
			03_render_2_bonus.c \
			04_geometry_1_bonus.c \
			04_geometry_2_bonus.c \
			04_geometry_3_bonus.c \
			04_geometry_4_bonus.c \
			05_projection_1_bonus.c \
			06_draw_1_bonus.c \
			06_draw_2_bonus.c \
			07_keys_1_bonus.c \
			08_graphic_cleanup_1_bonus.c \
			09_hooks_1_bonus.c

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

BONUS_OBJ_FILES = $(BONUS_SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_FILES)  
	$(CC) $(FLAGS) $(OBJ_FILES) -o $(NAME) $(LIBS) 

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f *.o
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -f fdf_bonus
	$(MAKE) -C libft fclean

re: fclean $(NAME)

$(BONUS): $(LIBFT) $(BONUS_OBJ_FILES)
	$(CC) $(FLAGS) $(BONUS_OBJ_FILES) $(LIBS) -o $(BONUS) 

bonus: $(BONUS)


.PHONY: fclean clean all re

#########Regras de teste
compile_gdb:
	$(CC) $(FLAGS) $(BONUS_SRC_FILES) libft/*.c -gdwarf-4 -o test.out $(LIBS)

test: compile_gdb
	gdb --args test.out maps/test_maps/elem-col.fdf

leak: compile_gdb
	valgrind --leak-check=full --show-leak-kinds=all -s ./test.out maps/test_maps/julia.fdf

######### Testando algoritmo de bresenham
compile_bres:
	$(CC) $(FLAGS) $(BRES_FILES) libft/*.c -gdwarf-4 -o test.out $(OTHER_LIBS) -Llibft -l:libft.a

bresenham: compile_bres
	./test.out

