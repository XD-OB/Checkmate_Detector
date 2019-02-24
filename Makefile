NAME = check

SRC = board.c pieces.c checkmate.c tools.c

HEADER = checkmate.h

OBJ = *.o

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(HEADER)
	@ gcc -c $(SRC) $(FLAG)
	@ gcc $(OBJ) -o $(NAME)

clean:
	@ /bin/rm -f $(OBJ)

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all
