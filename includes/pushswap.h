/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jla-chon <jla-chon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:09:35 by jla-chon          #+#    #+#             */
/*   Updated: 2024/05/08 20:04:31 by jla-chon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum s_i
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}					t_i;

typedef enum s_nums
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
	int				size;
	struct s_list	*list;
}					t_ls;

void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(int content);
void				ft_lstclear(t_list **lst);
int					ft_psfree(void *a, void *b, t_list **lst);
int					ft_checkandstock(t_list **numlst, int ac, char **av);
int					ft_addorder(t_list **node, t_i i);
void				ft_operate(t_ls *a, t_ls *b, t_i c);
int					ft_ordandop(t_ls *alist, t_ls *blist, t_list **olist,
						t_i i);
char				**ft_split(char const *s, char c);
int					ft_instlist(t_list **inst);
int					ft_lstcheck(t_list *lst);
int					ft_lsinit(t_ls *list, t_list *content, int size);
int					ft_algo(t_list *numlist, t_list **olist, int size);
int					ft_runnum(t_ls *alist, t_ls *blist, t_list **olist,
						int *nums);
int					ft_lstsize(t_list *lst);
int					sort3(t_ls *alst, t_list **olst);
void					ft_init(int num[7], t_ls *list);

#endif