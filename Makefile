CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = pipex

LIBFT = libft.a

SRC_FILES = mandatory/main.c mandatory/utils1.c mandatory/utils2.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c

BONUS_SRC_FILES = bonus/main.c bonus/utils1.c bonus/utils2.c bonus/utils3.c bonus/here_doc.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c

OBJ_FILES = $(SRC_FILES:.c=.o)

BONUS_OBJ_FILES = $(BONUS_SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	cd libft/ && make -silent
	$(CC) $(FLAGS) -o $@ $(OBJ_FILES) libft/$(LIBFT)

bonus: $(BONUS_OBJ_FILES)
	cd libft/ && make -silent
	$(CC) $(FLAGS) -o pipex $(BONUS_OBJ_FILES) libft/$(LIBFT)

clean:
	cd libft/ && make clean
	rm -f $(BONUS_OBJ_FILES)

fclean: clean
	cd libft/ && make fclean
	rm -f $(NAME)

re: fclean all