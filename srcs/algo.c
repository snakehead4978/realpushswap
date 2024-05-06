/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:21:41 by marvin            #+#    #+#             */
/*   Updated: 2024/05/06 17:23:30 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

typedef enum s_nums
{
	index,
	bestindex,
	bestrequired,
	min,
	max
}	t_nums;

void	ft_init(int	num[5], int firstnum)
{
	num[index] = 0;
	num[bestindex] = 0;
	num[bestrequired] = 0;
	num[min] = firstnum;
	num[max] = firstnum;
}

void	ft_lsinit(t_ls *list)
{
	t_list	*tmp;
	tmp = 0;
	list->list = &tmp;
	list->size = 0;
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	ft_absmax(int a, int b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (a < b)
		return (b);
	return (a);
}

int	ft_returnnum(int num, int size)
{
	if (num < size / 2)
		return (num);
	else
		return (num - size);
}

void	ft_evaluate(int sum, t_ls bl, int *nums, int size)
{
	if (sum * ft_returnnum(nums[index], size) >= 0)
	{
		if (ft_absmax(sum, ft_returnnum(nums[index], size)))
	}
}

int		ft_checkpos(t_list *alist, t_ls *bl, int *nums, int size)
{
	int	num;
	int	sum;
	int	i;
	t_list	*blist;

	i = 0;
	while (i++ < nums[index])
		alist = alist->next;
	num = alist->content;
	blist = *bl->list;
	sum = 0;
	while (!(blist->content <= num && blist->previous->content >= num) && !((num > nums[max] || num < nums[min]) && blist->content == max))
	{
		sum++;
		blist = blist->next;
	}
	return (ft_returnnum(sum, bl->size));
}

void	ft_setnum(int *num, t_list *alist, t_list *blist, int index)
{
	int	size;

	size = ft_lstsize(blist);
	
}

int ft_tmp(t_list **alist, t_list **olist, int size)
{
	t_ls	*blist;
	int		num[5];

	ft_lsinit(blist);
	ft_ordandop(alist, blist->list, olist, pa);
	ft_init(num, (*blist->list)->content);
	while (*alist)
	{
		while (num[index] < size && (num[index] == 0 || ft_abs(ft_returnnum(num[index], size)) < num[bestrequired]))
		{
			ft_checkpos(, blist, num);
			ft_setnum(num, alist, index);
			num[index]++;
		}
		if (!ft_runnum(num[1], alist, blist, olist))
			return (0);
	}
	return (1);
}
