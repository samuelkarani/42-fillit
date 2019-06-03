CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = fillit

SRC = fillit.c parser.c pieces.c pieces_helper.c \
		pieces_checks.c board.c board_helper.c libft.c \
		utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
