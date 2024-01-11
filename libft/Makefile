# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 12:27:08 by ymostows          #+#    #+#              #
#    Updated: 2023/12/18 16:13:31 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_atoi.c \
			  ft_bzero.c \
			  ft_calloc.c \
			  ft_isalnum.c \
			  ft_isalpha.c \
			  ft_isascii.c \
			  ft_isdigit.c \
			  ft_isprint.c \
			  ft_itoa.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_memcpy.c \
			  ft_memmove.c \
			  ft_memset.c \
			  ft_putchar_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c \
			  ft_putstr_fd.c \
			  ft_split.c \
			  ft_strchr.c \
			  ft_strdup.c \
			  ft_striteri.c \
			  ft_strjoin.c \
			  ft_strlcat.c \
			  ft_strlcpy.c \
			  ft_strlen.c \
			  ft_strmapi.c \
			  ft_strncmp.c \
			  ft_strcmp.c \
			  ft_strnstr.c \
			  ft_strrchr.c \
			  ft_substr.c \
			  ft_tolower.c \
			  ft_toupper.c \
			  ft_printf.c \
			  ft_printhex.c \
			  ft_printnum.c \
			  ft_printp.c \
			  ft_printstr.c \
			  get_next_line.c \
			  get_next_line_utils.c \

SRCS_BONUS	= ft_lstadd_back_bonus.c \
			  ft_lstadd_front_bonus.c \
			  ft_lstclear_bonus.c \
			  ft_lstdelone_bonus.c \
			  ft_lstiter_bonus.c \
			  ft_lstlast_bonus.c \
			  ft_lstmap_bonus.c \
			  ft_lstnew_bonus.c \
			  ft_lstsize_bonus.c
OBJS		= ${SRCS:.c=.o}
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}
NAME		= libft.a
CC			= gcc -Wall -Wextra -Werror

%.o: %.c libft.h
			${CC} -I. -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS} libft.h
			ar rcs ${NAME} ${OBJS}

bonus:		${OBJS_BONUS} libft.h
			ar rcs ${NAME} ${OBJS_BONUS}

clean:
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(SRCS_BONUS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

.PHONY:		all clean fclean re bonus

