/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:00:36 by jla-chon          #+#    #+#             */
/*   Updated: 2023/12/07 18:40:09 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
		new->next = new;
		new->previous = new;
	}
	else
	{
		if ((*lst)->previous)
		{
			(*lst)->previous->next = new;
			new->previous = (*lst)->previous;
		}
		else
		{
			(*lst)->next = new;
			new->previous = *lst;
		}
		new->next = *lst;
		(*lst)->previous = new;
	}
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->previous = 0;
	new->next = 0;
	return (new);
}

int	ft_findmax(t_list **lst)
{
	int		res;
	t_list	*tmp;

	tmp = *lst;
	res = tmp->content;
	tmp = tmp->next;
	while (tmp != *lst)
	{
		if (tmp->content > res)
			res = tmp->content;
		tmp = tmp->next;
	}
	return (res);
}
