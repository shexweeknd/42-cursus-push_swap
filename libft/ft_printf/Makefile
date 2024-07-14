NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

GARBAGE = *.o */*.o *.gch */*.gch *.out */*.out

SRCS = ft_printf.c \
		ft_put_addr.c \
		ft_putnbr_base.c \
		ft_put_unsigned_nbr.c \
		ft_putchar_i.c \
		ft_putstr.c \
		ft_putx.c \

# Colors variables
OBJS = $(SRCS:.c=.o)

GREEN = \033[0;32m

RED = \033[0;31m

BLUE = \033[0;34m

END = \033[0m

# Rules
.c.o:
	@echo "$(GREEN)###$(BLUE) Exec .c.o rule$(GREEN)###$(END)"
	@cc -c $(SRCS) -I ./

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)###$(BLUE) Exec all rule $(GREEN)###$(END)"
	@make .c.o
	@ar rc $(NAME) $(OBJS)
	@echo "$(GREEN)#Created: $(END) $(NAME)"
	@ranlib $(NAME)

clean: $(OBJS)
	@rm -rf $(OBJS) $(GARBAGE)
	@echo "$(RED)#Cleaned $(END) $(GARBAGE)"

fclean: clean
	@rm -rf $(NAME) */*.a
	@echo "$(RED)#Cleaned $(END) $(NAME)"

re: fclean
	@make all

.PHONY: all clean fclean re