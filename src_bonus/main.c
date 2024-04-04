/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:57:03 by tmaillar          #+#    #+#             */
/*   Updated: 2024/01/04 15:03:00 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	int		exit_code;

	if (argc < 5)
	{
		if (argc >= 2 && (ft_check_here_doc(argv[1]) == 1))
			return (ft_manage_error(1));
		return (ft_manage_error(2));
	}
	else if (argc < 6 && (ft_check_here_doc(argv[1]) == 1))
		return (ft_manage_error(1));
	if (!envp || envp[0][0] == '\0')
		ft_error(ft_put_error("Error on envp", "", "", 1), &data);
	data = ft_init_pipex(argc, argv, envp);
	exit_code = ft_pipex(&data);
	return (exit_code);
}
