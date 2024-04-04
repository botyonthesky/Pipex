# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 16:40:00 by tmaillar          #+#    #+#              #
#    Updated: 2023/10/04 14:00:13 by tmaillar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= libft.a

SRCS_FILES		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c  \
					ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
					ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
					ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
					ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
					ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
					ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
					ft_printf.c ft_put_memory_adress.c ft_putchar_p.c ft_putnbr_p.c \
					ft_putstr_p.c ft_check.c ft_convert.c get_next_line.c \
					get_next_line_utils.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
					ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
					ft_lstiter.c ft_lstmap.c ft_strtok.c

SRCS_DIR		= src

HEADERS			= libft.h		

HEADERS_DIR		= include

DIR_OBJS		= objets

SRCS			= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS 			= $(addprefix $(DIR_OBJS)/, $(SRCS_FILES:.c=.o))

CC				= cc

RM				= rm -f

CFLAGS			= -g3 -Wall -Wextra -Werror -g -fPIE -MD

all:			${NAME}

${NAME}: 		${OBJS}
				ar rcs $(NAME) $(OBJS)

${OBJS}:		$(DIR_OBJS)/%.o : $(SRCS_DIR)/%.c | $(DIR_OBJS)
				$(CC) $(CFLAGS) -c $< -o $@

clean: 
				${RM} ${OBJS}

fclean: 		clean
				${RM} ${NAME}
				$(RM) $(OBJS:.o=.d)

re:				fclean all

.PHONY:			all clean fclean re

-include $(OBJS:.o=.d)



