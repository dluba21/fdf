FRAMEWORKS=-framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall
NAME=fdf
SRCS=*.c
INCLUDES=libft/libft.a
HEADER=fdf.h

all: $(NAME)

$(NAME): $(HEADER)
	make -C libft/
	make -C minilibx_macos/
	cc $(SRCS) -o $(NAME) $(FLAGS) minilibx_macos/libmlx.a $(INCLUDES) $(FRAMEWORKS)

clean:
	@make -C libft/ clean
	@make -C minilibx_macos/ clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft/ fclean
	
re: fclean all

.PHONY: all clean fclean re bonus