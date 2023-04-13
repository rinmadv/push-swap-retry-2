/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:17:25 by madavid           #+#    #+#             */
/*   Updated: 2023/04/11 00:08:14 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstbeforelast(t_list *lst)
{
	int	size;
	int	i;

	i = 0;
	if (lst == NULL)
		return (NULL);
	size = ft_lstsize(lst);
	while (i < size - 2)
	{
		lst = lst->next;
		i++;
	}	
	return (lst);
}

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	while (lst != NULL)
	{
		f(lst->content);
		write(1, "\n", 1);
		lst = lst->next;
	}
}
