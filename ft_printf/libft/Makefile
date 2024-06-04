FLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
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
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

BONUS = ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c \
	ft_isnumber.c

OBJ = $(SRC:.c=.o)

ALLOBJS = $(OBJ) $(BONUS:.c=.o)

MAINSRC = main.c

MAINOBJ = $(MAINSRC:.c=.o)

all: $(NAME)

.c.o:
	@cc -c -g $(FLAGS) $(SRC) $(BONUS) -I .

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

debug: $(SRC) $(MAINSRC)
	@(cc -g $(SRC) $(MAINSRC) $(FLAGS) && ./a.out)

bonus: $(ALLOBJS)
	@ar rc $(NAME) $(ALLOBJS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ) $(ALLOBJS) *.out main.o

fclean: clean
	@rm -f $(NAME)

re: fclean all bonus

.PHONY: clean fclean all re bonus