/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg_two_three_five.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:24:48 by marine            #+#    #+#             */
/*   Updated: 2023/04/11 21:55:59 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_two(t_list **stack_a)
{	
	int	first;
	int	second;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	if (first > second)
		swap(*stack_a, 'a');
	return ;
}

int	find_pos_min(t_list *stack_a)
{
	int	min;
	int	pos;

	pos = 0;
	min = find_first_min(stack_a);
	while (stack_a->content != min)
	{
		stack_a = stack_a->next;
		pos++;
	}
	return (pos);
}

void	push_min(t_list **stack_a, t_list **stack_b, int size)
{
	int	pos_min;

	pos_min = find_pos_min(*stack_a);
	if ((size == 5 && pos_min == 4) || (size == 4 && pos_min == 3))
		reverserotate(stack_a, 'a');
	else if ((size == 5 && pos_min == 3) || (size == 4 && pos_min == 2))
	{
		reverserotate(stack_a, 'a');
		reverserotate(stack_a, 'a');
	}
	else if (size == 5 && pos_min == 2)
	{
		rotate(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if ((size == 5 && pos_min == 1) || (size == 4 && pos_min == 1))
		rotate(stack_a, 'a');
	push(stack_a, stack_b, 'b');
}

void	sort_three(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;
	if (first > second && first < third && second < third)
		return (swap(*stack_a, 'a'));
	if (first > second && first > third && second > third)
		return (swap(*stack_a, 'a'), reverserotate(stack_a, 'a'));
	if (first > second && first > third && second < third)
		return (rotate(stack_a, 'a'));
	if (first < second && first < third && second > third)
		return (swap(*stack_a, 'a'), rotate(stack_a, 'a'));
	if (first < second && first > third && second > third)
		return (reverserotate(stack_a, 'a'));
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	push_min(stack_a, stack_b, 5);
	push_min(stack_a, stack_b, 4);
	sort_three(stack_a);
	push(stack_b, stack_a, 'a');
	push(stack_b, stack_a, 'a');
}
