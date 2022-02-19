SRCS 	= 	ft_bzero.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_substr.c\
		ft_strtrim.c\
		ft_strrchr.c\
		ft_strnstr.c\
		ft_strncmp.c\
		ft_strmapi.c\
		ft_strlen.c\
		ft_memcmp.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_strjoin.c\
		ft_striteri.c\
		ft_strdup.c\
		ft_strchr.c\
		ft_split.c\
		ft_atoi.c\
		ft_putstr_fd.c\
		ft_putnbr_fd.c\
		ft_putendl_fd.c\
		ft_putchar_fd.c\
		ft_memset.c\
		ft_memmove.c\
		ft_memcpy.c\
		ft_memchr.c\
		ft_itoa.c\
		ft_isprint.c\
		ft_isdigit.c\
		ft_isascii.c\
		ft_isalpha.c\
		ft_isalnum.c\
		ft_calloc.c\
		get_next_line.c\
		get_next_line_utils.c\
		ft_atodb.c\
		ft_lstadd_back_bonus.c\
		ft_lstadd_front_bonus.c\
		ft_lstclear_bonus.c\
		ft_lstdelone_bonus.c\
		ft_lstiter_bonus.c\
		ft_lstlast_bonus.c\
		ft_lstmap_bonus.c\
		ft_lstnew_bonus.c\
		ft_printf.c\
		funcs_1.c\
		funcs_2.c\
		funcs_3.c\

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

HEADER	= libft.h

CC	= cc

LIBCC	= ar rcs

CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	${LIBCC}  $(NAME) $(OBJS)

clean:
	@rm -rf ${OBJS}

fclean:	clean
	@rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
