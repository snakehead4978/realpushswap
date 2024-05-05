


libft = libft.a


INC = -Iincludes -Ilibft/includes


.c.o : 
	cc -Wall -Werror -Wextra $(INC) -c -


build :
	$(MAKE) -C libft/ 


$(NAME) : build
		ar rcs ./libft/libft.a $@ $^

clean :
	$(MAKE) -C libft/ fclean