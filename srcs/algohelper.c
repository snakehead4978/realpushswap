/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algohelper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:06:48 by jla-chon          #+#    #+#             */
/*   Updated: 2024/05/13 18:12:47 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_init(int num[7], t_ls *list)
{
	int	num1;
	int	num2;

	num[index] = 0;
	num[bestindex] = 0;
	num[bestrequired] = -1;
	num[bestcosta] = 0;
	num[bestcostb] = 0;
	if (list->list)
	{
		num1 = list->list->content;
		num2 = list->list->next->content;
		if (num2 < num1)
		{
			num2 = num1;
			num1 = list->list->next->content;
		}
		num[min] = num1;
		num[max] = num2;
	}
}

static int	ft_cost(int costa, int costb)
{
	if (costa * costb > 0)
	{
		if (costa < 0)
		{
			if (costa < costb)
				return (-costa);
			return (-costb);
		}
		if (costa < costb)
			return (costb);
		return (costa);
	}
	else
	{
		if (costa - costb < 0)
			return (-(costa - costb));
		return (costa - costb);
	}
}

static int	ft_checkpos(t_ls *alist, t_ls *blist, int *nums)
{
	int		num;
	int		sum;
	t_list	*node;

	sum = 0;
	node = alist->list;
	while (sum++ < nums[index])
		node = node->next;
	num = node->content;
	node = blist->list;
	sum = 0;
	while (!(node->content < num && node->previous->content > num)
		&& !((num > nums[max] || num < nums[min])
			&& node->content == nums[max]))
	{
		sum++;
		node = node->next;
	}
	return (ft_returnnum(sum, blist->size));
}

static void	ft_setnum(int *num, t_ls *alist, int costb)
{
	int		costa;
	long	finalcost;

	costa = ft_returnnum(num[index], alist->size);
	finalcost = ft_cost(costa, costb);
	if (finalcost < num[bestrequired] || num[bestrequired] == -1)
	{
		num[bestrequired] = finalcost;
		num[bestcosta] = costa;
		num[bestcostb] = costb;
		num[bestindex] = num[index];
	}
}

int	ft_algo(t_ls *alist, t_ls *blist, t_list **olist)
{
	int	num[7];

	if (alist->size > 3)
		if (ft_ordandop(alist, blist, olist, pa))
			return (1);
	if (alist->size > 3)
		if (ft_ordandop(alist, blist, olist, pa))
			return (1);
	ft_init(num, blist);
	while (alist->size > 3)
	{
		while (num[index] < (int)alist->size)
		{
			ft_setnum(num, alist, ft_checkpos(alist, blist, num));
			num[index]++;
		}
		if (ft_runnum(alist, blist, olist, num))
			return (1);
	}
	return (0);
}
