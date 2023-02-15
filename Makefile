SRCS = ft_close3.c ft_heredoc.c gnl/get_next_line.c gnl/get_next_line_utils.c main.c ft_close.c ft_utils.c ft_close2.c ft_utils2.c 

NAME = pipex

NAME_BONUS = pipex_bonus

OBJS = ${SRCS:.c=.o}

GCC = cc

LIBRARY = -I. -I ./libft/ -L ./libft/ -lft -I ./gnl

CFLAGS = -Wall -Werror -Wextra

.c.o:
	${GCC} -g ${CFLAGS} -c -I. -I ./gnl $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	$(MAKE) -C libft
	${GCC} -g -o ${NAME} ${OBJS} ${LIBRARY} 

${NAME_BONUS}: ${OBJS}
	$(MAKE) -C libft
	${GCC} -g -o ${NAME} ${OBJS} ${LIBRARY} 

clean:
	rm -f ${OBJS}
	$(MAKE) clean -C libft

fclean: clean
	rm -f ${NAME}
	$(MAKE) fclean -C libft

re: fclean all

bonus: ${NAME_BONUS}

.PHONY: all re clean fclean