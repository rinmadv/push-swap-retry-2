/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general_indexing_presort.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:24:48 by marine            #+#    #+#             */
/*   Updated: 2023/04/11 00:08:14 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_first_min(t_list *stack_a)
{
	int		min;

	min = stack_a->content;
	while (stack_a->next != NULL)
	{
		stack_a = stack_a->next;
		if (stack_a->content < min)
			min = stack_a->content;
	}
	return (min);
}

int	find_next_min(t_list *stack_a, int old_min)
{
	int	new_min;

	new_min = INT_MAX;
	while (stack_a != NULL)
	{
		if (stack_a->content > old_min && stack_a->content < new_min)
			new_min = stack_a->content;
		stack_a = stack_a->next;
	}
	if (new_min == INT_MAX)
		return (old_min);
	else
		return (new_min);
}

void	indexing(t_list **stack_a, int size)
{
	int		min;
	int		i;
	t_list	*temp;

	i = 0;
	min = find_first_min(*stack_a);
	temp = *stack_a;
	while (i < size - 1)
	{
		while (*stack_a != NULL)
		{
			if ((*stack_a)->content == min)
				(*stack_a)->index = i;
			else if ((*stack_a)->content > min)
				(*stack_a)->index = i + 1;
			*stack_a = (*stack_a)->next;
		}
		*stack_a = temp;
		min = find_next_min(*stack_a, min);
		i++;
	}
	*stack_a = temp;
}

void	presort(t_list **stack_a, t_list **stack_b, int size)
{
	int	index_med;
	int	index_max;
	int	i;

	index_med = (size - 1) / 2 ;
	index_max = (size - 1);
	i = 0;
	while (i <= size)
	{
		if ((*stack_a)->index == index_max)
			rotate(stack_a, 'a');
		else if ((*stack_a)->index >= index_med)
			push(stack_a, stack_b, 'b');
		else
		{
			push(stack_a, stack_b, 'b');
			rotate(stack_b, 'b');
		}
		i++;
	}
}
