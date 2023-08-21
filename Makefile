NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror -c
FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
OTHER_LIBS = -lX11 -lXext -lmlx -lm

SRC_FILES = main.c

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
