/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:36:49 by jla-chon          #+#    #+#             */
/*   Updated: 2024/05/11 21:23:06 by jla-chon         ###   ########.fr       */
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
	if (ac == 1)
		return (0);
	if (ft_checkandstock(&numlist, ac, av))
		return (ft_psfree(0, 0, numlist));
	if (ft_lsinit(&blist, 0, 0))
		return (ft_psfree(blist, 0, numlist));
	if (ft_lsinit(&alist, numlist, ft_lstsize(numlist)))
		return (ft_psfree(blist, 0, numlist));
	if (ft_algo(alist, blist, &olist))
		return (ft_psfree(alist, blist, olist));
	if (ft_sort3(alist, blist, &olist))
		return (ft_psfree(alist, blist, olist));
	if (blist->list && ft_pushback(alist, blist, &olist))
		return (ft_psfree(alist, blist, olist));
	ft_shorten(&olist);
	return (ft_free(alist, blist, olist));
}
