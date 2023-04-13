/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:24:48 by marine            #+#    #+#             */
/*   Updated: 2023/04/11 00:08:14 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	if (s == 'a')
		write(1, "sa\n", 3);
	else if (s == 'b')
		write(1, "sb\n", 3);
}

void	swap_both(t_list *stack_a, t_list *stack_b)
{
	swap(stack_a, 'x');
	swap(stack_b, 'x');
	write(1, "ss\n", 3);
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
	if (s == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}
