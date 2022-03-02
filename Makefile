NAME = test.a

CFLAGS = -Wall -Werror -Wextra

ARFLAGS = -crs

CC = gcc

RM = rm -f

PNTC = 

PNTO = $(PNTC:.c=.o)

Green = \033[0;32m

NC = \033[0m

all : make

make : $(PNTC)
	$(MAKE) -C ./libft make
	@$(CC) $(CFLAG) -c $(PNTC) ./libft/libft.a
	@echo "Compilation : $(Green)OK$(NC)"
	@ar $(ARFLAGS) $(NAME) $(PNTO)
	@echo "creation des points 'O' : $(Green)OK$(NC)"

clean :
	$(MAKE) -C ./libft clean
	@/bin/$(RM) $(PNTO)
	@echo "Clean : $(Green)OK$(NC)"

fclean : clean
	$(MAKE) -C ./libft fclean
	@/bin/$(RM) $(NAME)
	@echo "Fclean : $(Green)OK$(NC)"

re : clean fclean all

.PHONY : all clean fclean re