/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push_swap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:24:48 by marine            #+#    #+#             */
/*   Updated: 2023/04/11 00:05:28 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	swap(t_list *stack, char s)
{
	int	temp_content;
	int	temp_index;

	if (stack != NULL && ft_lstsize(stack) > 1)
	{
		temp_content = stack->content;
		temp_index = stack->index;
		stack->content = stack->next->content;
		stack->index = stack->next->index;
		stack->next->content = temp_content;
		stack->next->index = temp_index;
	}
	(void) s;
}

void	swap_both(t_list *stack_a, t_list *stack_b)
{
	swap(stack_a, 'x');
	swap(stack_b, 'x');
}

void	push(t_list **takefrom, t_list **addto, char s)
{
	t_list	*temp;

	if (*takefrom != NULL)
	{
		temp = (*takefrom)->next;
		(*takefrom)->next = NULL;
		ft_lstadd_front(addto, *takefrom);
		*takefrom = temp;
	}
	(void) s;
}
