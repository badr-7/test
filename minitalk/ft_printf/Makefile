NAME = libftprintf.a

SRCS =	ft_printf.c\
		ft_putnbr.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_unsignednb.c\
		ft_hexalower.c\
		ft_hexaupper.c\
		ft_p.c\

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS} libftprintf.h
			ar rc ${NAME} ${OBJS}

all : ${NAME}


clean : 
		${RM} ${OBJS}

fclean : clean 
		${RM} ${NAME}

re : fclean all

.PHONY = all clean fclean re