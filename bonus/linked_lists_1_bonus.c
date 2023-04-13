/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists_1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:17:25 by madavid           #+#    #+#             */
/*   Updated: 2023/04/11 20:00:16 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

t_list	*ft_lstnew(int contenu)
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list));
	if (newlist == NULL)
		return (NULL);
	newlist->content = contenu;
	newlist->index = -1;
	newlist->next = NULL;
	return (newlist);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			new->next = (*lst);
		}
		*lst = new;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst != NULL)
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
		temp = temp->next;
		temp->next = NULL;
	}
	else
		*lst = new ;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*p;

	if (lst)
	{
		p = *lst;
		while (*lst)
		{
			p = (*lst)->next;
			free(*lst);
			*lst = NULL;
			*lst = p;
		}
	}
}
