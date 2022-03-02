NAME = test.a

CFLAGS = -Wall -Werror -Wextra

ARFLAGS = -crs

CC = gcc

RM = rm -f

PNTC = echo.c

Green = \033[0;32m

NC = \033[0m

all : make

make : $(PNTC)
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAG) -o $(NAME) $(PNTC) ./libft/libft.a
	@echo "Compilation : $(Green)OK$(NC)"
	
clean :
	@$(MAKE) -C ./libft clean
	@echo "Clean : $(Green)OK$(NC)"

fclean : clean
	@$(MAKE) -C ./libft fclean
	@$(RM) $(NAME)
	@echo "Fclean : $(Green)OK$(NC)"

re : clean fclean all

.PHONY : all clean fclean re