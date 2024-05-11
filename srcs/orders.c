/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:39:20 by snek              #+#    #+#             */
/*   Updated: 2024/05/11 16:42:12 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_addorder(t_list **node, t_i i)
{
	t_list	*new;

	new = ft_lstnew(i);
	if (!new)
		return (1);
	ft_lstadd_back(node, new);
	return (0);
}

int	ft_ordandop(t_ls *alist, t_ls *blist, t_list **olist, t_i i)
{
	if (ft_addorder(olist, i))
		return (1);
	ft_operate(alist, blist, i);
	return (0);
}
