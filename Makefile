
NAME = push_swap

BONUS = checker

SRC_C = 	algo.c \
		algohelper.c \
		arguments.c \
		freepushswap.c \
		ft_split.c \
		lstlib.c \
		lstsizeandcheck.c \
		operations.c \
		orders.c \
		pushback.c \
		shorten. \
		sort3.c

SRC =	pushswap.c 

SRC_B = checker_bonus.c

INC = -Iincludes

OBJ_C = $(SRC_C:.c=.o)

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

CC = cc

FLAGS = -Wall -Werror -Wexta
	cc -Wall -Werror -Wextra $(INC)

$(NAME) : $(OBJ) $(OBJ_C)
		$(CC) $(FLAGS) $(INC) -o $@ $^

all: $(NAME) $(BONUS)

$(BONUS) : $(OBJ_B) $(OBJ_C)
		$(CC) $(FLAGS) $(INC) -o $@ $^

clean :
	rm -rf $(OBJ) $(OBJ_B) $(OBJ_C)

fclean : clean
	rm -rf $(NAME) $(BONUS)

re : fclean all

.PHONY: all clean fclean re