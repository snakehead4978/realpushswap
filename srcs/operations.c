/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:16:12 by snek              #+#    #+#             */
/*   Updated: 2024/05/08 19:58:45 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_swap(t_ls *lst)
{
	t_list	*tmp;
	t_list	*node;

	node = lst->list;
	if (!node || !node->next || node->next == node)
		return ;
	if (node->next->next == node)
	{
		lst->list = node->next;
		return ;
	}
	tmp = node->next;
	tmp->next->previous = node;
	node->previous->next = tmp;
	node->next = tmp->next;
	tmp->next = node;
	tmp->previous = node->previous;
	node->previous = tmp;
	lst->list = tmp;
}

static void	ft_next(t_ls *lst)
{
	lst->list = lst->list->next;
}

static void	ft_prev(t_ls *lst)
{
	lst->list = lst->list->previous;
}

static void	ft_push(t_ls *lsta, t_ls *lstb)
{
	t_list	*tmp;

	tmp = lsta->list;
	if (!lsta->list)
		return ;
	if (lsta->list->next && lsta->list->next != lsta->list)
	{
		lsta->list->previous->next = lsta->list->next;
		lsta->list->next->previous = lsta->list->previous;
		lsta->list = lsta->list->next;
	}
	else
		lsta->list = 0;
	lsta->size--;
	lstb->size++;
	ft_lstadd_back(&lstb->list, tmp);
}

void	ft_operate(t_ls *a, t_ls *b, t_i c)
{
	if (c == sa)
		ft_swap(a);
	else if (c == sb)
		ft_swap(b);
	else if (c == ss)
		ft_swap(a), ft_swap(b);
	else if (c == pa)
		ft_push(a, b);
	else if (c == pb)
		ft_push(b, a);
	else if (c == ra)
		ft_next(a);
	else if (c == rb)
		ft_next(b);
	else if (c == rr)
		ft_next(a), ft_next(b);
	else if (c == rra)
		ft_prev(a);
	else if (c == rrb)
		ft_prev(b);
	else if (c == rrr)
		ft_prev(a), ft_prev(b);
}
