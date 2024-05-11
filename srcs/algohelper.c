/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algohelper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:06:48 by jla-chon          #+#    #+#             */
/*   Updated: 2024/05/11 18:02:14 by jla-chon         ###   ########.fr       */
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

int	ft_returnnum(int num, size_t size)
{
	if (num <= size / 2)
		return (num);
	else
		return (num - size);
}

static int	ft_checkpos(t_ls *alist, t_ls *blist, int *nums)
{
	int		num;
	int		sum;
	int		i;
	t_list	*bnode;

	i = 0;
	bnode = blist->list;
	num = alist->list->content;
	while (!(bnode->content < num && bnode->previous->content > num)
		&& !((num > nums[max] || num < nums[min]) && bnode->content == max))
	{
		sum++;
		bnode = bnode->next;
	}
	return (ft_returnnum(sum, blist->size));
}

static void	ft_setnum(int *num, t_ls *alist, t_ls *blist, int costb)
{
	int		costa;
	long	finalcost;

	costa = ft_returnnum(num[index], alist->size);
	finalcost = (long)costa + ((long)costb * -1);
	if (finalcost < 0)
		finalcost = finalcost * -1;
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
		if (ft_ordandop(alist, blist->list, olist, pa))
			return (1);
	if (alist->size > 3)
		if (ft_ordandop(alist, blist->list, olist, pa))
			return (1);
	ft_init(num, blist);
	while (alist->size > 3)
	{
		while (num[index] < alist->size)
		{
			ft_setnum(num, alist, blist, ft_checkpos(alist, blist, num));
			num[index]++;
		}
		if (ft_runnum(num, alist, blist, olist))
			return (1);
	}
	return (0);
}
