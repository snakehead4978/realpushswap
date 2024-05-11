/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:09:35 by jla-chon          #+#    #+#             */
/*   Updated: 2024/05/11 21:06:54 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_i
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rrb,
	rra,
	rrr
}					t_i;

typedef enum e_nums
{
	index,
	bestindex,
	bestrequired,
	bestcosta,
	bestcostb,
	min,
	max
}					t_nums;

typedef struct s_list
{
	int				content;
	struct s_list	*previous;
	struct s_list	*next;
}					t_list;

typedef struct s_listandsize
{
	size_t			size;
	struct s_list	*list;
}					t_ls;

void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(int content);
size_t				ft_lstsize(t_list *lst);

// arguments parser
int					ft_lsinit(t_ls **list, t_list *content, size_t size);
int					ft_checkandstock(t_list **numlst, int ac, char **av);
char				**ft_split(char const *s, char c);

// Adding Operating and Stocking
int					ft_addorder(t_list **node, t_i i);
void				ft_operate(t_ls *a, t_ls *b, t_i c);
int					ft_ordandop(t_ls *alist, t_ls *blist, t_list **olist,
						t_i i);

// Algorithm
int					ft_algo(t_ls *lista, t_ls *listb, t_list **olist);
int					ft_runnum(t_ls *alist, t_ls *blist, t_list **olist,
						int *nums);
int					ft_sort3(t_ls *alist, t_ls *blist, t_list **olst);
int					ft_returnnum(int num, size_t size);
int					ft_pushback(t_ls *alist, t_ls *blist, t_list **olist);

// Print
void				ft_shorten(t_list **olist);

// Free
int					ft_free(t_ls *alist, t_ls *blist, t_list *olist);
int					ft_psfree(t_ls *alist, t_ls *blist, t_list *olist);

#endif