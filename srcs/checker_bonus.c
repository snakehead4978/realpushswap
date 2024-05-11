/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:35:26 by jla-chon          #+#    #+#             */
/*   Updated: 2024/05/11 18:05:45 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

static int	ft_lstcheck(t_list *lst)
{
	t_list	*first;

	first = lst;
	while (lst && lst->next != first)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

static int	ft_instcheck(t_ls *alist, t_ls *blist, char *ord)
{
	if (!ft_strcmp(ord, "sa\n"))
		ft_operate(alist, blist, sa);
	else if (!ft_strcmp(ord, "sb\n"))
		ft_operate(alist, blist, sb);
	else if (!ft_strcmp(ord, "pa\n"))
		ft_operate(alist, blist, pa);
	else if (!ft_strcmp(ord, "pb\n"))
		ft_operate(alist, blist, pb);
	else if (!ft_strcmp(ord, "ra\n"))
		ft_operate(alist, blist, ra);
	else if (!ft_strcmp(ord, "rb\n"))
		ft_operate(alist, blist, rb);
	else if (!ft_strcmp(ord, "rr\n"))
		ft_operate(alist, blist, rr);
	else if (!ft_strcmp(ord, "rra\n"))
		ft_operate(alist, blist, rra);
	else if (!ft_strcmp(ord, "rrb\n"))
		ft_operate(alist, blist, rrb);
	else if (!ft_strcmp(ord, "rrr\n"))
		ft_operate(alist, blist, rrr);
	else
		return (1);
	return (0);
}

static int	ft_instlist(t_ls *alist, t_ls *blist)
{
	size_t	check;
	char	res[5];
	int		i;

	res[4] = 0;
	check = 1;
	i = 0;
	while (check)
	{
		if (i == 4)
			return (1);
		check = read(0, &res[i], 1);
		if (res[i] == '\n')
		{
			res[i + 1] = 0;
			if (ft_instcheck(alist, blist, res))
				return (1);
			i = 0;
		}
		else
			i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*numlist;
	t_ls	*blist;
	t_ls	*alist;

	numlist = 0;
	if (ft_checkandstock(&numlist, ac, av))
		return (1);
	if (ft_lsinit(&blist, 0, 0))
		return (ft_psfree(0, 0, numlist));
	if (ft_lsinit(&alist, numlist, ft_lstsize(numlist)))
		return (ft_psfree(blist, 0, numlist));
	if (ft_instlist(alist, blist))
		return (ft_psfree(alist, blist, 0));
	if (ft_lstcheck(alist) && !blist)
		write(stdout, "OK\n", 4);
	else
		write(stdout, "KO\n", 4);
	return (ft_free(alist, blist, 0));
}
