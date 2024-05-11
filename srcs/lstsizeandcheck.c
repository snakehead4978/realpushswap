/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsizeandcheck.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:51:33 by snek              #+#    #+#             */
/*   Updated: 2024/05/11 18:00:14 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	ft_lstsize(t_list *lst)
{
	t_list	*first;
	size_t	a;

	a = 1;
	first = lst;
	if (!lst)
		return (0);
	lst = lst->next;
	while (lst && lst != first)
	{
		a++;
		lst->next;
	}
	return (a);
}

int	ft_lsinit(t_ls **list, t_list *content, size_t size)
{
	*list = malloc(sizeof(t_ls));
	if (*list)
		return (1);
	(*list)->list = content;
	(*list)->size = size;
	return (0);
}

int	ft_oneway(t_list *lst)
{
	t_list	*first;
	int		a;

	a = 1;
	while (a)
	{
		if (lst->content < lst->previous->content)
			a = 0;
		lst = lst->next;
	}
	a = 1;
	first = lst;
	lst = lst->next;
	while (a && lst != first)
	{
		if (lst->content < lst->previous->content)
			a = 0;
		lst = lst->next;
	}
	return (a);
}
