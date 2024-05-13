/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:07:20 by jla-chon          #+#    #+#             */
/*   Updated: 2024/05/13 18:12:55 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_firstpush(t_ls *alist, t_ls *blist, t_list **olist, int num[2])
{
	if (ft_ordandop(alist, blist, olist, pb))
		return (1);
	ft_findminmax(alist->list, num);
	while (blist->size && blist->list->content < alist->list->content)
	{
		if ((blist->list->content < alist->list->previous->content
				&& blist->list->content > num[0])
			|| (blist->list->content < num[0]
				&& alist->list->content != num[0]))
		{
			if (ft_ordandop(alist, blist, olist, rra))
				return (1);
		}
		else
		{
			if (ft_ordandop(alist, blist, olist, pb))
				return (1);
			ft_findminmax(alist->list, num);
		}
	}
	return (0);
}

static int	ft_secondpushcase(t_ls *alist, t_ls *blist, t_list **olist,
		int num[2])
{
	if (!blist->size)
		return (0);
	if (blist->list->content > num[1])
	{
		while (alist->list->previous->content != num[1])
		{
			if (ft_ordandop(alist, blist, olist, rra))
				return (1);
		}
	}
	else
	{
		while (!(alist->list->content > blist->list->content
				&& blist->list->content > alist->list->previous->content))
		{
			if (ft_ordandop(alist, blist, olist, rra))
				return (1);
		}
	}
	if (ft_firstpush(alist, blist, olist, num))
		return (1);
	return (0);
}

static int	ft_findpushcase(t_ls *alist, t_ls *blist, t_list **olist,
		int nums[2])
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
	if (ft_firstpush(alist, blist, olist, nums))
		return (1);
	if (ft_secondpushcase(alist, blist, olist, nums))
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
	currentindex = 1;
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
	int	num[2];

	ft_findminmax(alist->list, num);
	if (ft_findpushcase(alist, blist, olist, num))
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
