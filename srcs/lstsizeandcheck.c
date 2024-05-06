/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsizeandcheck.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snek <snek@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:51:33 by snek              #+#    #+#             */
/*   Updated: 2023/12/14 01:06:42 by snek             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*first;
	int		a;

	a = 1;
	first = lst;
	if (lst)
		lst = lst->next;
	while (lst && lst != first)
	{
		a++;
		lst->next;
	}
	return (a);
}

int	ft_lstcheck(t_list *lst)
{
	t_list	*first;
	int		a;

	a = 1;
	if (!lst)
		return (0);
	if (!lst->next || lst->next == lst)
		return (a);
	lst = lst->next;
	while (a && lst != first)
	{
		if (lst->content < lst->previous->content)
			a = 0;
		lst = lst->next;
	}
	return (a);
}

int	ft_oneway(t_list *lst)
{
	t_list	*first;
	int		a;
	
	a = 1;
	while (a)
	{
		if (lst->content < lst->previous->content)
			a = 0;
		lst = lst->next;
	}
	a = 1;
	first = lst;
	lst = lst->next;
	while (a && lst != first)
	{
		if (lst->content < lst->previous->content)
			a = 0;
		lst = lst->next;
	}
	return (a);
}
