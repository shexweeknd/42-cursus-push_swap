#MAIN VARS
CC 				= cc -g

CFLAGS 			= -Wall -Wextra -Werror

NAME 			= push_swap

BONUS_NAME		= checker

FUNC_DIR		= functions/

#FILES NAME
MAIN_FILE 		= push_swap.c \

FUNC_FILES 		= family_utils_one.c \
				family_utils_two.c \
				push_swap_entry.c \
				push_swap_exit.c \
				push_swap_error.c \
				push_swap_utils.c \
				push_swap_fixer.c \
				ft_op_a.c \
				ft_op_b.c \
				ft_op_ab.c \
				ft_pseudo_op_a.c \
				ft_pseudo_op_b.c \
				ft_pseudo_op_ab.c \
				ft_turk_one.c \
				ft_turk_two.c \
				ft_utils_one.c \
				ft_utils_two.c \

BONUS_FILE		= checker.c \

FUNC            = $(addprefix $(FUNC_DIR), $(FUNC_FILES))

#OBJECTS
MAIN_OBJ		= $(MAIN_FILE:%.c=output/%.o)
BONUS_OBJ 		= $(BONUS_FILE:%.c=output/%.o)
FUNC_OBJS 		= $(FUNC:$(FUNC_DIR)%.c=output/%.o)

# Colors variables
GREEN = \033[0;32m

RED = \033[0;31m

BLUE = \033[0;34m

END = \033[0m

#DEPENDECIES
LIBFT_DIR 		= libft

#LIBRARIES
LIBFT_LIB		= -L$(LIBFT_DIR) -lft
LIBS 			= $(LIBFT_LIB)

#INCLUDES
LIBFT_INC		= -I$(LIBFT_DIR)/includes
PUSH_SWAP_INC	= -Iincludes
INCLUDES		= $(LIBFT_INC) $(PUSH_SWAP_INC)

#MAKE FUNCTIONS
define Compile
	$(CC) $(CFLAGS) $(INCLUDES) -c $(1) -o $(2)
endef

define MakeLibs
	make $(1) -C $(LIBFT_DIR)
endef

define Makebin
	$(call MakeLibs,all)
	$(CC) $(CFLAGS) $(1) $(LIBS) -o $(2)
endef

#MAIN RULES
all: $(NAME)

output:
	mkdir -p output

output/%.o: %.c | output
	$(call Compile,$<,$@)

output/%.o: $(FUNC_DIR)%.c | output
	$(call Compile,$<,$@)

output/%.o: $(BONUS_DIR)%.c | output
	$(call Compile,$<,$@)

$(NAME): $(MAIN_OBJ) $(FUNC_OBJS)
	$(call Makebin,$^,$@)

clean:
	$(call MakeLibs,clean)
	rm -rf output/*.o

fclean: clean
	$(call MakeLibs,fclean)
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ) $(FUNC_OBJS)
	$(call Makebin,$^,$@)

.PHONY: all clean fclean re bonus