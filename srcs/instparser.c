/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instparser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:35:30 by jla-chon          #+#    #+#             */
/*   Updated: 2024/05/06 16:25:48 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_strcmp(char *s1, char *s2)
{
	size_t			i;

	i = 0;
	while (s1[i] == s2[i] && s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

static int	ft_instcheck(t_list **inst, char *ord)
{
	if (!ft_strcmp(ord, "sa\n"))
		return (ft_addorder(inst, sa));
	else if (!ft_strcmp(ord, "sb\n"))
		return (ft_addorder(inst, sb));
	else if (!ft_strcmp(ord, "pa\n"))
		return (ft_addorder(inst, pa));
	else if (!ft_strcmp(ord, "pb\n"))
		return (ft_addorder(inst, pb));
	else if (!ft_strcmp(ord, "ra\n"))
		return (ft_addorder(inst, ra));
	else if (!ft_strcmp(ord, "rb\n"))
		return (ft_addorder(inst, rb));
	else if (!ft_strcmp(ord, "rr\n"))
		return (ft_addorder(inst, rr));
	else if (!ft_strcmp(ord, "rra\n"))
		return (ft_addorder(inst, rra));
	else if (!ft_strcmp(ord, "rrb\n"))
		return (ft_addorder(inst, rrb));
	else if (!ft_strcmp(ord, "rrr\n"))
		return (ft_addorder(inst, rrr));
	else
		return (1);
}

int	ft_instlist(t_list **inst)
{
	size_t	check;
	char	buf[1];
	char	res[5];
	int		i;

	res[4] = 0;
	check = 1;
	*buf = 0;
	i = 0;
	while (check)
	{
		if (i == 4)
			return (ft_psfree(0, 0, inst));
		check = read(0, buf, 1);
		res[i] = *buf;
		if (res[i] == '\n')
		{
			res[i + 1] = 0;
			if (ft_instcheck(inst, res))
				return (ft_psfree(0, 0, inst));
			i = 0;
		}
		else
			i++;
	}
	return (0);
}
