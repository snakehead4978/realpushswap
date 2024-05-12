/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freepushswap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:32:49 by jla-chon          #+#    #+#             */
/*   Updated: 2024/05/12 17:50:17 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_cl(t_list *lst)
{
	if (lst->next != 0)
		ft_cl(lst->next);
	free(lst);
}

static void	ft_lstclear(t_list **lst)
{
	if (!*lst)
		return ;
	if ((*lst)->previous)
		(*lst)->previous->next = 0;
	ft_cl(*lst);
	*lst = 0;
}

int	ft_psfree(t_ls *alist, t_ls *blist, t_list *olist)
{
	if (alist)
	{
		ft_lstclear(&alist->list);
		free(alist);
	}
	if (blist)
	{
		ft_lstclear(&blist->list);
		free(blist);
	}
	ft_lstclear(&olist);
	write(2, "Error\n", 7);
	return (1);
}

int	ft_free(t_ls *alist, t_ls *blist, t_list *olist)
{
	if (alist)
	{
		ft_lstclear(&alist->list);
		free(alist);
	}
	if (blist)
	{
		ft_lstclear(&blist->list);
		free(blist);
	}
	ft_lstclear(&olist);
	return (0);
}
