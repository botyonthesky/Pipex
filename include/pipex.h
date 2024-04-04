/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:04:58 by tmaillar          #+#    #+#             */
/*   Updated: 2024/01/08 07:20:32 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include "../libft/include/libft.h"

typedef struct s_pipex
{
	char	**envp;
	char	**argv;
	char	*cmd_path;
	char	**cmd;
	int		argc;
	int		heredoc;
	int		fd_in;
	int		fd_out;
	int		*pipe;
	int		n_cmd;
	int		child;
	int		*pid;
}		t_pipex;

/*---------------------Pipex base----------------------------*/

int		main(int argc, char **argv, char **envp);
t_pipex	ft_init_data(void);
t_pipex	ft_init_pipex(int argc, char **argv, char **envp);
void	ft_create_pipe(t_pipex *data);
int		ft_pipex(t_pipex *data);

/*---------------------Process----------------------------*/

int		ft_parent(t_pipex *data);
void	ft_child(t_pipex *data);

/*-------------------------Path-----------------------------*/

char	**ft_manage_space(char *av);
char	**ft_manage_cmd(char *av);
char	*ft_manage_path(char *cmd, t_pipex *data);
char	*ft_get_cmd_path(char *cmd, char **path);
char	**ft_get_path(char **envp);
char	**ft_create_path(char **path);
char	*ft_get_envp_path(char **envp);

/*---------------------Errors case----------------------------*/

char	**ft_free(char **tab);
int		ft_manage_error(int x);
void	ft_error(int error_stat, t_pipex *data);
int		ft_put_error(char *str, char *str2, char *str3, int erno);

/*---------------------Utils----------------------------*/

int		ft_strnstr_p(const char *big, const char *little, size_t len);
void	ft_remove_quote(char *str);
void	ft_restore_space(char **tab);
void	ft_replace_space(char *str);
char	*ft_remove_slash(char *str);
int		ft_check_space_backslash(char *str);
void	ft_free_str(char *str, char **tab);

/*---------------------Close----------------------------*/

void	ft_close_pipe(t_pipex *data);
void	ft_close_fd(t_pipex *data);

/*---------------------Manage fd----------------------------*/

void	ft_manage_fileno(int input, int output, t_pipex *data);
void	ft_manage_fd_out(t_pipex *data);
void	ft_manage_fd_in(t_pipex *data);

/*---------------------Here_doc----------------------------*/

void	ft_manage_heredoc(t_pipex *data);
void	ft_here_doc(char **av);
int		ft_check_here_doc(char *str);
void	ft_apply_heredoc(int *pipefd, char **av);

#endif
