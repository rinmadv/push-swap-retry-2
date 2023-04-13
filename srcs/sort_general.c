/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:24:48 by marine            #+#    #+#             */
/*   Updated: 2023/04/11 00:08:14 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	bring_min_to_top(t_list **stack_a, int size)
{
	int		pos_min;
	t_list	*temp;

	pos_min = 1;
	temp = *stack_a;
	while ((*stack_a)->index != 0)
	{
		pos_min++;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = temp;
	if (pos_min <= size / 2)
	{
		while ((*stack_a)->index != 0)
			rotate(stack_a, 'a');
	}
	else
	{
		while ((*stack_a)->index != 0)
			reverserotate(stack_a, 'a');
	}	
}

int	sort_general(t_list **stack_a, t_list **stack_b, int size)
{
	t_match		*match;

	match = malloc(sizeof(t_match));
	if (match == NULL)
		return (-1);
	match->size = size;
	match->len_stack_b = size - 1;
	indexing(stack_a, size);
	presort(stack_a, stack_b, size);
	while (*stack_b)
	{
		match_nodes(stack_a, stack_b, match);
		match->len_stack_b--;
	}
	if ((*stack_a)->index != 0)
		bring_min_to_top(stack_a, size);
	free (match);
	return (0);
}
