/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:07:36 by jla-chon          #+#    #+#             */
/*   Updated: 2024/05/10 19:57:47 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_findcase(t_list *node)
{
	int	a;
	int	b;
	int	c;

	a = node->content;
	b = node->next->content;
	c = node->previous->content;
	if (a < b && b > c && a < c)
		return (1);
	else if (a < b)
		return (2);
	else if (b > c)
		return (3);
	else if (a < c)
		return (4);
	else
		return (5);
}

int	sort3(t_ls *alist, t_ls *blist, t_list **olist)
{
	int	a;

	a = ft_findcase(alist->list);
	if (a == 1)
		return (ft_ordandop(alist, blist, olist, rra) || ft_ordandop(alist,
				blist, olist, sa));
	else if (a == 2)
		return (ft_ordandop(alist, blist, olist, ra));
	else if (a == 3)
		return (ft_ordandop(alist, blist, olist, sa) || ft_ordandop(alist,
				blist, olist, rra));
	else if (a == 4)
		return (ft_ordandop(alist, blist, olist, sa));
	else
		return (ft_ordandop(alist, blist, olist, rra));
}

static int	ft_pushsmall(t_ls *alist, t_ls *blist, t_list **olist)
{
	while (blist->size && blist->list->content < alist->list->content)
	{
		if (ft_ordandop(alist, blist, olist, pb))
			return (1);
	}
	return (0);
}

static int	ft_pushmed(t_ls *alist, t_ls *blist, t_list **olist, )
{
	while (blist->size && blist->list->content < alist->list->content)
	{
		if (blist->list->content < alist->list->previous->content)
		{
			if (ft_ordandop(alist, blist, olist, ra))
				return (1);
		}
		else
			if (ft_ordandop(alist, blist, olist, pb))
				return (1);
	}
	return (0);
}

static int	ft_firstpush(t_ls *alist, t_ls *blist, t_list **olist)
{
	while (blist->size && blist->list->content < alist->list->content)
	{
		if (alist->list->previous->content < alist->list->previous->previous->content && blist->list->content < alist->list->previous->content)
		{
			if (ft_ordandop(alist, blist, olist, ra))
				return (1);
		}
		else
			if (ft_ordandop(alist, blist, olist, pb))
				return (1);
	}
	return (0);
}

static int	ft_secondpushcase(t_ls *alist, t_ls *blist, t_list **olist)
{
	if (!blist->size)
		return (0);
	while (alist->list->previous->content < alist->list->previous->previous->content && blist->list->content > alist->list->previous->content)
	{
		if (ft_ordandop(alist, blist, olist, ra))
			return (1);
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
	else if (num > alist->list->next->content && num < alist->list->previous->content)
	{
		if (ft_ordandop(alist, blist, olist, rra))
			return (1);
	}
	if (ft_firstpush(alist, blist, olist))
		return (1);
	return (0);
}

int	pushback(t_ls *alist, t_ls *blist, t_list **olist)
{
	if (ft_findpushcase(alist, blist, olist))
		return (1);
	if (ft_secondpushcase(alist, blist, olist))
		return (1);
	return (0);
}
