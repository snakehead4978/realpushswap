/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:35:26 by jla-chon          #+#    #+#             */
/*   Updated: 2024/05/07 18:27:32 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_operateandcheck(t_list *lista, t_list *ordlist)
{
	t_list	*firstorder;
	t_list	*listb;

	listb = 0;
	firstorder = ordlist;
	while (ordlist->next != firstorder)
	{
		ft_operate(&lista, &listb, ordlist->content);
		ordlist = ordlist->next;
	}
	if (ft_lstcheck(lista) && !listb)
		write(stdout, "OK\n", 4);
	else
		write(stdout, "KO\n", 4);
}

int	main(int ac, char **av)
{
	t_list	*numlist;
	t_list	*ordlist;

	numlist = 0;
	ordlist = 0;
	if (ft_checkandstock(&numlist, ac, av))
		return (1);
	if (ft_instlist(&ordlist))
		return (1);
	ft_operateandcheck(numlist, ordlist);
	return (0);
}
