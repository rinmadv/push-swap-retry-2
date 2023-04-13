/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate_reverse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:24:48 by marine            #+#    #+#             */
/*   Updated: 2023/04/11 00:08:14 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_list **stack, char s)
{
	t_list	*temp;

	if (*stack != NULL && ft_lstsize(*stack) > 1)
	{
		temp = (*stack)->next;
		ft_lstadd_back(stack, *stack);
		*stack = temp;
	}
	if (s == 'a')
		write(1, "ra\n", 3);
	else if (s == 'b')
		write(1, "rb\n", 3);
}

void	rotate_both(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, 'x');
	rotate(stack_b, 'x');
	write(1, "rr\n", 3);
}

void	reverserotate(t_list **stack, char s)
{
	t_list	*stack_last;
	t_list	*stack_beforelast;

	if (*stack != NULL && ft_lstsize(*stack) > 1)
	{
		stack_last = ft_lstlast(*stack);
		stack_beforelast = ft_lstbeforelast(*stack);
		ft_lstadd_front(stack, stack_last);
		stack_beforelast->next = NULL;
	}
	if (s == 'a')
		write(1, "rra\n", 4);
	else if (s == 'b')
		write(1, "rrb\n", 4);
}

void	reverserotate_both(t_list **stack_a, t_list **stack_b)
{
	reverserotate(stack_a, 'x');
	reverserotate(stack_b, 'x');
	write(1, "rrr\n", 4);
}
