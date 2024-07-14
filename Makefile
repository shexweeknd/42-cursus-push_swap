NAME = push_swap

FLAGS = -Wall -Wextra -Werror

GARBAGE = *.o */*.o *.gch */*.gch *.out */*.out *.a

SRCS = push_swap.c \
		family_utils_one.c \
		family_utils_two.c \
		push_swap_entry.c \
		push_swap_utils.c \
		push_swap_fixer.c \
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

BONUS_SRCS = checker.c \
		push_swap_entry.c \
		ft_op_a.c \
		ft_op_b.c \
		ft_op_ab.c \
		ft_op_ab_utils.c \
		ft_utils_one.c \
		ft_utils_two.c \

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Colors variables
GREEN = \033[0;32m

RED = \033[0;31m

BLUE = \033[0;34m

END = \033[0m

# Rules
.c.o:
	@echo "$(GREEN)###$(BLUE) Exec .c.o rule$(GREEN)###$(END)"
	@cc -c -g $(SRCS) $(BONUS_SRCS) -I libft -I libft/ft_printf -I ./

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)###$(BLUE) Exec all rule $(GREEN)###$(END)"
	@cd ./libft &&\
	make all &&\
	cd ..
	@cc $(FLAGS) -g $(OBJS) -o $(NAME) -L./libft -lft

clean: $(OBJS)
	@cd ./libft/ &&\
	make clean &&\
	cd ../
	@rm -rf $(OBJS) $(BONUS_OBJS) $(GARBAGE)
	@echo "$(RED)#Cleaned $(END) $(GARBAGE)"

fclean: clean
	@cd ./libft/ &&\
	make fclean &&\
	cd ../
	@rm -rf $(NAME)
	@rm -rf checker
	@echo "$(RED)#Cleaned $(END) $(NAME)"

re: clean fclean
	@make all

bonus: $(BONUS_OBJS)
	@echo "$(GREEN)###$(BLUE) Exec all rule $(GREEN)###$(END)"
	@cd ./ft_printf &&\
	make all clean &&\
	cd .. &&\
	cc $(FLAGS) -g $(BONUS_OBJS) -o checker -L ./ft_printf/ -lftprintf

.PHONY: all clean fclean re bonus