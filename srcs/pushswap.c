/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:36:49 by jla-chon          #+#    #+#             */
/*   Updated: 2024/05/08 19:50:23 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_list	*numlist;
	t_list	*olist;
	t_ls	*blist;
	t_ls	*alist;

	numlist = 0;
	olist = 0;
	if (ft_checkandstock(&numlist, ac, av))
		return (1);
	if (ft_init(0, &blist, 0, 0))
		return (1);
	if (ft_init(0, &alist, numlist, ft_lstsize(numlist)))
		return (ft_psfree(blist, 0, 0));
	ft_algo(&alist, &blist, &olist);
	ft_sort3();


	return (0);
}