/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:38:05 by jla-chon          #+#    #+#             */
/*   Updated: 2024/05/08 19:40:00 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_splitfree(char **list, int errnum)
{
	size_t	n;

	n = 0;
	while (list[n])
		free(list[n++]);
	free(list[n]);
	free(list);
	return (errnum);
}

static int	ft_psatoi(int *num, const char *nptr)
{
	int			i;
	long		sign;
	long		res;

	sign = 1;
	i = 0;
	res = 0;
	if (nptr[i++] == '-')
		sign = -1;
	else
		i--;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		res = res * 10 + nptr[i++] - '0';
	res = res * sign;
	if (res < -2147483648 || res > 214748367 || nptr[i])
		return (0);
	free(num);
	num = malloc(sizeof(int) * 1);
	if (num)
		return (0);
	*num = (int)res;
	return (1);
}

static int	ft_psadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;
	int		num1;
	int		num2;

	num1 = *(int *)new->content;
	tmp = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (tmp->next != 0)
		{
			num2 = *(int *)tmp->content;
			if (num2 == num1)
				return (0);
			tmp = tmp->next;
		}
		tmp->next = new;
	}
	return (1);
}

static int	ft_arguments(t_list **numlst, char **av)
{
	int		*num;
	int		i;
	t_list	*new;

	i = 0;
	while (av[i])
	{
		num = 0;
		if (ft_psatoi(num, av[i]))
			return (ft_psfree(num, 0, *numlst));
		new = ft_lstnew(num);
		if (!new)
			return (ft_psfree(num, 0, *numlst));
		if(!ft_psaddback(numlst, new))
			return (ft_psfree(num, 0, *numlst));
		i++;
	}
	return (1);
}

int	ft_checkandstock(t_list **numlst, int ac, char **av)
{
	char	*splitav;

	if (ac <= 1)
		return (0);
	if (ac == 2)
	{
		splitav = ft_split(av[1], ' ');
		if (!splitav)
		{
			write(stderr, "Error\n", 6);
			return (1);
		}
		if (ft_arguments(numlst, splitav))
		{
			write(stderr, "Error\n", 6);
			return (ft_splitfree(splitav, 1));
		}
		ft_splitfree(splitav, 0);
	}
	else if (ft_arguments(numlst, &av[1]))
	{
		write(stderr, "Error\n", 6);
		return (1);
	}
	return (0);
}
