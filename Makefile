
NAME = pipex

NAME_BONUS = pipex_bonus

SRCS = ft_close3.c ft_heredoc.c gnl/get_next_line.c gnl/get_next_line_utils.c main.c ft_close.c ft_utils.c ft_close2.c ft_utils2.c 

SRCS_BONUS = bonus/ft_close3.c bonus/ft_heredoc.c gnl/get_next_line.c gnl/get_next_line_utils.c bonus/main.c bonus/ft_close.c bonus/ft_utils.c bonus/ft_close2.c bonus/ft_utils2.c

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

GCC = cc

LIBRARY = -I. -I ./libft/ -L ./libft/ -lft -I ./gnl

CFLAGS = -Wall -Werror -Wextra

.c.o:
	${GCC} -g ${CFLAGS} -c -I. -I ./gnl $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	$(MAKE) -C libft
	${GCC} -g -o ${NAME} ${OBJS} ${LIBRARY} 

bonus: ${NAME_BONUS}

clean:
	rm -f ${OBJS}
	rm -f ${OBJS_BONUS}
	$(MAKE) clean -C libft

fclean: clean
	rm -f ${NAME} ${NAME_BONUS}
	$(MAKE) fclean -C libft

re: fclean all

re_bonus: fclean bonus

${NAME_BONUS}: ${OBJS_BONUS}
	$(MAKE) -C libft
	${GCC} -g -o ${NAME_BONUS} ${OBJS_BONUS} ${LIBRARY}


.PHONY: re clean fclean 