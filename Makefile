NAME = test.a

CFLAGS = -Wall -Werror -Wextra -lreadline -lncurses

ARFLAGS = -crs

CC = gcc

RM = rm -f

PNTC = exit.c

Green = \033[0;32m

NC = \033[0m

all : make

make : $(PNTC)
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAG) -o $(NAME) $(PNTC) ./libft/libft.a
	@echo "[$(Green)TEST$(NC)]Compilation : $(Green)OK$(NC)"
	
clean :
	@$(MAKE) -C ./libft clean
	@echo "[$(Green)TEST$(NC)]Clean : $(Green)OK$(NC)"

fclean : clean
	@$(MAKE) -C ./libft fclean
	@$(RM) $(NAME)
	@echo "[$(Green)TEST$(NC)]Fclean : $(Green)OK$(NC)"

re : clean fclean all

.PHONY : all clean fclean re