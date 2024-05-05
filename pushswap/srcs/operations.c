/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snek <snek@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:16:12 by snek              #+#    #+#             */
/*   Updated: 2023/12/14 01:06:43 by snek             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_swap(t_list **lst)
{
	t_list	*tmp;

	if (!*lst || !(*lst)->next || (*lst)->next == *lst)
		return ;
	if ((*lst)->next->next == *lst)
	{
		*lst = (*lst)->next;
		return ;
	}
	tmp = (*lst)->next;
	tmp->next->previous = (*lst);
	(*lst)->previous->next = tmp;
	(*lst)->next = tmp->next;
	tmp->next = (*lst);
	tmp->previous = (*lst)->previous;
	(*lst)->previous = tmp;
	*lst = tmp;
}

static void	ft_next(t_list **lst)
{
	*lst = (*lst)->next;
}

static void	ft_prev(t_list **lst)
{
	*lst = (*lst)->previous;
}

static void	ft_push(t_list **lsta, t_list *lstb)
{
	t_list	*tmp;

	tmp = *lsta;
	if ((*lsta)->next && (*lsta)->next != *lsta)
	{
		(*lsta)->previous->next = (*lsta)->next;
		(*lsta)->next->previous = (*lsta)->previous;
		*lsta = (*lsta)->next;
	}
	else
		*lsta = 0;
	ft_lstadd_back(&lstb, tmp);
}

void	ft_operate(t_list **a, t_list **b, t_i	c)
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
