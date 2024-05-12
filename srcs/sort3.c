/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:07:36 by jla-chon          #+#    #+#             */
/*   Updated: 2024/05/12 16:06:14 by jla-chon         ###   ########.fr       */
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
	if (a < b && b < c)
		return (0);
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

int	ft_sort3(t_ls *alist, t_ls *blist, t_list **olist)
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
	else if (a == 5)
		return (ft_ordandop(alist, blist, olist, rra));
	else
		return (0);
}
