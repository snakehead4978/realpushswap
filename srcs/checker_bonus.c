/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:35:26 by jla-chon          #+#    #+#             */
/*   Updated: 2024/05/06 17:23:28 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"



int	main(int ac, char **av)
{
	t_list	*numlist;
	t_list	*ordlist;

	numlist = 0;
	ordlist = 0;
	if (ft_checkandstock(&numlist, ac, (char *)av))
		return (1);
	if (ft_instlist(&ordlist))
		return (1);
	
	return (0);
}
