/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:10:52 by tmaillar          #+#    #+#             */
/*   Updated: 2023/05/04 13:29:35 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*new;

	new = lst;
	if (!lst || !f)
		return ;
	while (new)
	{
		f(new->content);
		new = new->next;
	}
}
