/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:38:05 by jla-chon          #+#    #+#             */
/*   Updated: 2024/05/12 21:37:14 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_splitfree(char **list)
{
	size_t	n;

	n = 0;
	while (list[n])
		free(list[n++]);
	free(list[n]);
	free(list);
	return (1);
}

static int	ft_psatoi(int *num, const char *nptr)
{
	int		i;
	long	sign;
	long	res;

	sign = 1;
	i = 0;
	res = 0;
	if (nptr[i++] == '-')
		sign = -1;
	else
		i--;
	if (nptr[i] < '0' || nptr[i] > '9')
		return (1);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		res = res * 10 + nptr[i++] - '0';
	res = res * sign;
	if (res < -2147483648 || res > 214748367 || nptr[i])
		return (1);
	*num = (int)res;
	return (0);
}

static int	ft_psaddback(t_list **lst, t_list *new)
{
	t_list	*node;

	node = (*lst);
	if (!node)
	{
		ft_lstadd_back(lst, new);
		return (0);
	}
	while (new->content != node->content)
	{
		if (node->next == *lst)
		{
			ft_lstadd_back(lst, new);
			return (0);
		}
		node = node->next;
	}
	return (1);
}

static int	ft_arguments(t_list **numlst, char **av)
{
	int		num;
	int		i;
	t_list	*new;

	i = 0;
	if (!*av)
		return (1);
	while (av[i])
	{
		num = 0;
		if (ft_psatoi(&num, av[i]))
			return (1);
		new = ft_lstnew(num);
		if (!new)
			return (1);
		if (ft_psaddback(numlst, new))
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkandstock(t_list **numlst, int ac, char **av)
{
	char	**splitav;

	if (ac == 2)
	{
		splitav = ft_split(av[1], ' ');
		if (!splitav)
			return (1);
		if (ft_arguments(numlst, splitav))
			return (ft_splitfree(splitav));
		ft_splitfree(splitav);
	}
	else if (ft_arguments(numlst, &av[1]))
		return (1);
	return (0);
}
