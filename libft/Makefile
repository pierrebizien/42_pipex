SRCS = ft_isascii.c ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c \
ft_atoi.c ft_isdigit.c ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c \
ft_bzero.c ft_isprint.c ft_memmove.c ft_split.c ft_strlcpy.c ft_strtrim.c \
ft_calloc.c ft_itoa.c ft_memset.c ft_strchr.c ft_strlen.c ft_substr.c \
ft_isalnum.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c \
ft_isalpha.c ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c ft_toupper.c

SRCS_BONUS = ft_lstadd_back.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstsize.c \
ft_lstadd_front.c ft_lstdelone.c ft_lstlast.c ft_lstnew.c

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -c -I.

INCLUDE = ./

INCLUDE_BONUS = ../

.c.o :
	${CC} ${CFLAGS} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rc -o ${NAME} ${OBJS}

all:	${NAME} 

clean:
	rm -f ${OBJS} ${OBJS_BONUS}

fclean: clean
	rm -f ${NAME}

re: fclean all;

bonus: ${OBJS_BONUS} ${OBJS}
	ar rc -o ${NAME} ${OBJS} ${OBJS_BONUS}
