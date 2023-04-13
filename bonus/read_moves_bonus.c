/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_moves_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:17:25 by madavid           #+#    #+#             */
/*   Updated: 2023/04/11 20:15:16 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

t_move	*ft_movenew(char *contenu)
{
	t_move	*newlist;

	newlist = malloc(sizeof(t_move));
	if (newlist == NULL)
		return (NULL);
	newlist->content = contenu;
	newlist->next = NULL;
	return (newlist);
}

t_move	*ft_movelast(t_move *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	ft_moveadd_back(t_move **lst, char *new)
{
	t_move	*temp;
	t_move	*new_move;

	new_move = ft_movenew(new);
	if (new_move == NULL)
		return (1);
	if (*lst != NULL)
	{
		temp = ft_movelast(*lst);
		temp->next = new_move;
		temp = temp->next;
		temp->next = NULL;
	}
	else
		*lst = new_move ;
	return (0);
}

void	ft_moveclear(t_move **lst)
{
	t_move	*p;

	if (lst)
	{
		p = *lst;
		while (*lst)
		{
			p = (*lst)->next;
			free((*lst)->content);
			(*lst)->content = NULL;
			free(*lst);
			*lst = NULL;
			*lst = p;
		}
	}
}

int	fill_lst_move(t_move **lst_move)
{
	t_move	*begin;
	char	*move;

	begin = *lst_move;
	move = get_next_line(0);
	while (move)
	{
		if (ft_moveadd_back(lst_move, move))
		{
			*lst_move = begin;
			ft_moveclear(lst_move);
			return (-1);
		}
		move = get_next_line(0);
	}
	return (0);
}
