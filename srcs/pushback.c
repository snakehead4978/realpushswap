/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:07:20 by jla-chon          #+#    #+#             */
/*   Updated: 2024/05/12 17:05:11 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_firstpush(t_ls *alist, t_ls *blist, t_list **olist)
{
	int	prevnum;
	int	prevprevnum;

	while (blist->size && blist->list->content < alist->list->content)
	{
		prevnum = alist->list->previous->content;
		prevprevnum = alist->list->previous->previous->content;
		if (prevnum < prevprevnum && blist->list->content < prevnum)
		{
			if (ft_ordandop(alist, blist, olist, ra))
				return (1);
		}
		else if (ft_ordandop(alist, blist, olist, pb))
			return (1);
	}
	return (0);
}

static int	ft_secondpushcase(t_ls *alist, t_ls *blist, t_list **olist)
{
	int	prevnum;
	int	prevprevnum;

	if (!blist->size)
		return (0);
	prevnum = alist->list->previous->content;
	prevprevnum = alist->list->previous->previous->content;
	while (prevnum < prevprevnum && blist->list->content > prevnum)
	{
		if (ft_ordandop(alist, blist, olist, ra))
			return (1);
		prevnum = alist->list->previous->content;
		prevprevnum = alist->list->previous->previous->content;
	}
	if (ft_firstpush(alist, blist, olist))
		return (1);
	return (0);
}

static int	ft_findpushcase(t_ls *alist, t_ls *blist, t_list **olist)
{
	int	num;

	num = blist->list->content;
	if (num > alist->list->content && num < alist->list->next->content)
	{
		if (ft_ordandop(alist, blist, olist, ra))
			return (1);
	}
	else if (num > alist->list->next->content
		&& num < alist->list->previous->content)
	{
		if (ft_ordandop(alist, blist, olist, rra))
			return (1);
	}
	if (ft_firstpush(alist, blist, olist))
		return (1);
	if (ft_secondpushcase(alist, blist, olist))
		return (1);
	return (0);
}

static int	ft_rightorder(t_ls *alist)
{
	int		min;
	int		index;
	int		currentindex;
	t_list	*node;

	min = alist->list->content;
	index = 0;
	currentindex = 0;
	node = alist->list->next;
	while (node != alist->list)
	{
		if (min > node->content)
		{
			min = node->content;
			index = currentindex;
		}
		node = node->next;
		currentindex++;
	}
	return (ft_returnnum(index, alist->size));
}

int	ft_pushback(t_ls *alist, t_ls *blist, t_list **olist)
{
	int	index;

	if (ft_findpushcase(alist, blist, olist))
		return (1);
	index = ft_rightorder(alist);
	while (index)
	{
		if (index < 0)
		{
			index++;
			if (ft_ordandop(alist, blist, olist, rra))
				return (1);
		}
		else
		{
			index--;
			if (ft_ordandop(alist, blist, olist, ra))
				return (1);
		}
	}
	return (0);
}
