SRCS = main.c

NAME = pipex

OBJS = ${SRCS:.c=.o}

GCC = cc

LIBRARY = -I. -I ./libft/ -L ./libft/ -lft

CFLAGS = -Wall -Werror -Wextra

.c.o:
	${GCC} -g ${CFLAGS} -c -I.  $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	$(MAKE) -C libft
	${GCC} -g -o ${NAME} ${OBJS} ${LIBRARY} 

clean:
	rm -f ${OBJS}
	$(MAKE) clean -C libft

fclean:
	rm -f ${NAME}
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all re clean fclean