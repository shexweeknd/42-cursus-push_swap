#MAIN VARS
CC 			= cc -g

FLAGS 		= -Wall -Wextra -Werror -lm

NAME 		= libft.a

#FILE NAMES
SRCS 		= ft_abs.c \
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
			ft_strlen_no_nl.c \
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
			ft_str_twodim_dup.c \
			get_next_line.c \
			ft_printf.c \
			ft_putnbr_base.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_isdecimal.c \

BONUS 		= ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \

#OBJECT FILES
OBJS 		= $(SRCS:%.c=output/%.o)

ALLOBJS 	= $(OBJS) $(BONUS:%.c=output/%.o)

#MAIN RULES
all			: $(NAME)

output:
	mkdir -p output

output/%.o	: functions/%.c | output
				$(CC) $(CFLAGS) -Iincludes -o $@ -c $<

$(NAME)		: $(OBJS)
				ar rcs $(NAME) $^

bonus		: $(ALLOBJS)
				ar rcs $(NAME) $^

clean		:
				rm -rf $(OBJS) $(ALLOBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all bonus

.PHONY: clean fclean all re bonus