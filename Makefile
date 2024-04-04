# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 08:51:20 by tmaillar          #+#    #+#              #
#    Updated: 2023/10/20 08:51:23 by tmaillar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= pipex

NAME_BONUS			= pipex_bonus

SRCS_FILES			= main.c p_utils.c p_heredoc.c p_path.c p_error.c p_pipe.c \
						p_cmd.c p_utils_space.c p_parent.c p_child.c p_close.c \
						p_manage_fd.c

SRCS_DIR			= src

SCRS_BONUS_FILES	= main.c p_utils_bonus.c p_heredoc_bonus.c p_path_bonus.c \
						p_error_bonus.c p_pipe_bonus.c p_cmd_bonus.c \
						p_utils_space_bonus.c p_parent_bonus.c p_child_bonus.c \
						p_close_bonus.c p_manage_fd_bonus.c

SRCS_BONUS_DIR		= src_bonus

HEADERS				= pipex.h

HEADERS_DIR			= include

HEADERS				= pipex_bonus.h

HEADERS_DIR			= include_bonus

DIR_OBJS			= objets

DIR_OBJS_BONUS		= objets_bonus

SRCS				= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

SRCS_BONUS			= $(addprefix $(SRCS_BONUS_DIR)/, $(SCRS_BONUS_FILES))

OBJS				= $(addprefix $(DIR_OBJS)/, $(SRCS_FILES:.c=.o))

OBJS_BONUS			= $(addprefix $(DIR_OBJS_BONUS)/, $(SCRS_BONUS_FILES:.c=.o))

LIBFT_DIR			= ./libft

LIBFT				= ./libft/libft.a

RM					= rm -f

CC					= cc

CFLAGS				= -Wall -Wextra -Werror -g -MD


all:				$(NAME)

bonus:				$(NAME_BONUS)

$(NAME):			$(LIBFT) $(OBJS)
					$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(NAME_BONUS):		$(LIBFT) $(OBJS_BONUS)
					$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)

$(OBJS):			$(DIR_OBJS)/%.o : $(SRCS_DIR)/%.c | $(DIR_OBJS)
					$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_BONUS):		$(DIR_OBJS_BONUS)/%.o : $(SRCS_BONUS_DIR)/%.c | $(DIR_OBJS_BONUS)
					$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):		
					$(MAKE) -C $(LIBFT_DIR)

clean:			
					$(MAKE) clean -C $(LIBFT_DIR)
					$(RM) $(NAME)
					$(RM) $(OBJS)
					$(RM) $(OBJS:.o=.d)

fclean:				clean
					$(MAKE) fclean -C $(LIBFT_DIR)
					$(RM) $(NAME)
					$(RM) $(NAME_BONUS)
					$(RM) $(OBJS)
					$(RM) $(OBJS_BONUS)
					$(RM) $(OBJS:.o=.d)
					$(RM) $(OBJS_BONUS:.o=.d)

re:					fclean all

.PHONY:				all clean fclean re libft bonus

-include $(OBJS:.o=.d)
-include $(OBJS_BONUS:.o=.d)
