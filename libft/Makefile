FLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_abs.c \
	ft_atoi.c \
	ft_atol.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_contentlen.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_isint.c \
	ft_isnumber.c \
	ft_isspace.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	word_len.c \
	word_len_sep.c \
	ft_split.c \
	ft_split_by.c \
	ft_free_splitted.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	sort_long_tab.c \
	get_twodim_size.c \
	get_next_line.c \
	get_next_line_utils.c \

BONUS = ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c \

OBJ = $(SRC:.c=.o)

ALLOBJS = $(OBJ) $(BONUS:.c=.o)

MAINSRC = main.c

MAINOBJ = $(MAINSRC:.c=.o)

.c.o:
	@cc -c -g $(FLAGS) $(SRC) $(BONUS) -I ./ -I ./ft_printf/

all: $(NAME)

$(NAME): $(OBJ)
	@cd ft_printf &&\
	make all &&\
	cp libftprintf.a ../$(NAME) &&\
	cd ..
	@make .c.o
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

bonus: $(ALLOBJS)
	@ar rc $(NAME) $(ALLOBJS)
	@ranlib $(NAME)

clean:
	@cd ft_printf &&\
	make clean &&\
	cd ..
	@rm -f $(OBJ) $(ALLOBJS) a.out main.o

fclean: clean
	@cd ft_printf &&\
	make fclean &&\
	cd ..
	@rm -f $(NAME)

re: fclean all bonus

.PHONY: clean fclean all re bonus