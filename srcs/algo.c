/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:21:41 by marvin            #+#    #+#             */
/*   Updated: 2024/05/13 17:21:05 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_returnnum(int num, size_t size)
{
	if (num <= (int)size / 2)
		return (num);
	else
		return (num - size);
}

static int	ft_movea(t_ls *alist, t_ls *blist, t_list **olist, int *nums)
{
	if (nums[bestcosta] > 0)
	{
		nums[bestcosta]--;
		if (nums[bestcostb] > 0)
		{
			nums[bestcostb]--;
			return (ft_ordandop(alist, blist, olist, rr));
		}
		return (ft_ordandop(alist, blist, olist, ra));
	}
	nums[bestcosta]++;
	if (nums[bestcostb] < 0)
	{
		nums[bestcostb]++;
		return (ft_ordandop(alist, blist, olist, rrr));
	}
	return (ft_ordandop(alist, blist, olist, rra));
}

static int	ft_moveb(t_ls *alist, t_ls *blist, t_list **olist, int *nums)
{
	if (nums[bestcostb] > 0)
	{
		nums[bestcostb]--;
		return (ft_ordandop(alist, blist, olist, rb));
	}
	nums[bestcostb]++;
	return (ft_ordandop(alist, blist, olist, rrb));
}

int	ft_runnum(t_ls *alist, t_ls *blist, t_list **olist, int *nums)
{
	while (nums[bestcosta] != 0 || nums[bestcostb] != 0)
	{
		if (nums[bestcosta])
		{
			if (ft_movea(alist, blist, olist, nums))
				return (1);
		}
		else
		{
			if (ft_moveb(alist, blist, olist, nums))
				return (1);
		}
	}
	if (ft_ordandop(alist, blist, olist, pa))
		return (1);
	nums[index] = 0;
	nums[bestrequired] = -1;
	if (blist->list->content > nums[max])
		nums[max] = blist->list->content;
	if (blist->list->content < nums[min])
		nums[min] = blist->list->content;
	return (0);
}
