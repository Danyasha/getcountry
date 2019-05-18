NAME = get_stat
FILES = get_stat.c list_functions.c get_next_line.c
FLAGS = -Wall -Werror -Wextra -g
LIBA = -L libft/ -lft
FILESO = ${SRC:.c=.o}
all: $(NAME)


$(NAME): $(FILESO)
	make -C ./libft/
	gcc $(FLAGS) -o $(NAME) $(FILES) $(LIBA) 
%.o:%.c
	gcc $(FLAGS) $(INCL) -o $@ -c $<

clean:
	rm -f $(FILESO)
	make clean -C ./libft/
fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/
re: fclean all