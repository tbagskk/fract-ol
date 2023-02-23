NAME = a.out

SRCS =	src/main.c \
		src/fractol.c \
		src/other.c \
		src/hook.c \
		src/color.c \
		src/textures.c

		

OBJS =	${SRCS:.c=.o}

GCC = gcc -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(GCC) $(OBJS) -o $(NAME) libmlx42.a -I include -lglfw -L "/Users/gcherqui/.brew/opt/glfw/lib/"

all: $(NAME)

clean:
	rm -rf ${OBJS}

fclean:	clean
	rm -rf $(NAME)

re:	fclean all