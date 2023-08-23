NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror -c
FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
OTHER_LIBS = -lX11 -lXext -lmlx -lm

SRC_FILES = main.c \
			init.c \
			draw.c \
			render.c \
			00_parsemap.c

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

compile_gdb:
	$(CC) $(FLAGS) $(SRC_FILES) -g3 -o test.out $(OTHER_LIBS) -Llibft -l:libft.a

test: compile_gdb
	gdb --args test.out maps/test_maps/42.fdf

leak: compile_gdb
	valgrind --leak-check=full ./test.out maps/test_maps/42.fdf
