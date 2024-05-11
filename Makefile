
libft = libft.a


INC = -Iincludes -Ilibft/includes


.c.o : 
	cc -Wall -Werror -Wextra $(INC) -c -

$(NAME) :
		ar rcs ./libft/libft.a $@ $^

clean :
	$(MAKE) -C libft/ fclean