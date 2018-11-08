
NAME = lem-in

SRCS = main.c \
		reading_rooms.c \
		reading_connects.c \
		array_connect.c \
		algo.c \
		finding_rooms.c \
		compring.c \
		printing.c \
		crossing.c \
		creating.c \
		clearing.c \

LIB = -L libft/ -lft
OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

libft: 
	make -C ./libft

$(NAME): libft $(OBJ)
	gcc $(CFLAGS) -g $(OBJ) -o $(NAME) $(LIB) -I ./

clean:
	/bin/rm -f $(OBJ)
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $< -I libft/

.PHONY: all clean fclean re libft

.NOTPARALLEL: all clean fclean re libft
