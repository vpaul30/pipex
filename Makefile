CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = pipex_bonus

LIBFT = libft.a

SRC_FILES = main_bonus.c gnl/get_next_line.c gnl/get_next_line_utils.c

OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	cd libft/ && make -silent
	$(CC) $(FLAGS) -o $@ $(OBJ_FILES) libft/$(LIBFT)

clean:
	cd libft/ && make clean
	rm -f $(OBJ_FILES)

fclean: clean
	cd libft/ && make fclean
	rm -f $(NAME)

re: fclean all