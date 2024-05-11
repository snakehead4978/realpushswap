NAME = push_swap

BONUS = checker

SRC_C = algo.c \
		algohelper.c \
		arguments.c \
		freepushswap.c \
		ft_split.c \
		lstlib.c \
		lstsizeandcheck.c \
		operations.c \
		orders.c \
		pushback.c \
		shorten.c \
		sort3.c

SRC = pushswap.c 

SRC_B = checker_bonus.c

INC = -Iincludes

SRCD = srcs/

OBJ_C = $(addprefix $(SRCD), $(SRC_C:.c=.o))

OBJ = $(addprefix $(SRCD), $(SRC:.c=.o))

OBJ_B = $(addprefix $(SRCD), $(SRC_B:.c=.o))

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3

.c.o :
	$(CC) $(CFLAGS) $(INC) -c -o $@ $^

$(NAME): $(OBJ_C) $(OBJ)
	$(CC) $(FLAGS) $(INC) -o $@ $^

all: $(NAME) $(BONUS)

$(BONUS): $(OBJ_C) $(OBJ_B)
	$(CC) $(FLAGS) $(INC) -o $@ $^

clean:
	rm -rf $(OBJ) $(OBJ_B) $(OBJ_C)

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re