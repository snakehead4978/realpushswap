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

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
		new->next = new;
		new->previous = new;
	}
	else
	{
		(*lst)->previous->next = new;
		new->previous = (*lst)->previous;
		(*lst)->previous = new;
		new->next = (*lst);
		*lst = new;
	}
}

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
		(*lst)->previous->next = new;
		new->previous = (*lst)->previous;
		(*lst)->previous = new;
		new->next = (*lst);
	}
}

void	ft_lstremove(t_list **lst, t_list *node)
{
	if (!*lst)
		return ;
	node->previous->next = node->next;
	node->next->previous = node->previous;
	if (*lst == node)
		*lst = node->next;
	if (node->next == node)
		*lst = 0;
	free(node);
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
