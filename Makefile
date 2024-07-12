NAME = push_swap

FLAGS = -Wall -Wextra -Werror

GARBAGE = *.o */*.o *.gch */*.gch *.out */*.out *.a

SRCS = push_swap.c \
		family_utils_one.c \
		family_utils_two.c \
		push_swap_entry.c \
		push_swap_utils.c \
		push_swap_fixer.c \
		checker.c \
		ft_op_a.c \
		ft_op_b.c \
		ft_op_ab.c \
		ft_op_ab_utils.c \
		ft_turk_one.c \
		ft_turk_two.c \
		ft_utils_one.c \
		ft_utils_two.c \
		ft_utils_debug_one.c \
		ft_utils_debug_two.c

OBJS = $(SRCS:.c=.o)

# Colors variables
GREEN = \033[0;32m

RED = \033[0;31m

BLUE = \033[0;34m

END = \033[0m

# Rules
.c.o:
	@echo "$(GREEN)###$(BLUE) Exec .c.o rule$(GREEN)###$(END)"
	@cc -c -g $(SRCS) -I ft_printf -I ft_printf/libft -I ./

all: $(OBJS)
	@echo "$(GREEN)###$(BLUE) Exec all rule $(GREEN)###$(END)"
	@cd ./ft_printf &&\
	make all clean &&\
	mv ./libftprintf.a ../ &&\
	cd .. &&\
	cc $(FLAGS) -g $(OBJS) -o $(NAME) -L. -lftprintf
	make clean

debug: re
	@echo "$(GREEN)###$(BLUE) Exec debug rule$(GREEN)###$(END)"
	@cc $(FLAGS) -g main.c -L. -lftprintf && ./a.out | cat -e

clean: $(OBJS)
	@rm -rf $(OBJS) $(GARBAGE)
	@echo "$(RED)#Cleaned $(END) $(GARBAGE)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)#Cleaned $(END) $(NAME)"

re: fclean
	@make all

.PHONY: all clean fclean re bonus