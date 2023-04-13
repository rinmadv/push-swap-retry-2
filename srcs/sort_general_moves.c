/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general_moves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:24:48 by marine            #+#    #+#             */
/*   Updated: 2023/04/11 00:08:14 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	bring_top_a(t_list **stack_a, t_match *match)
{
	if ((*match).cheapest_a_pos <= (*match).len_stack_a / 2)
	{
		while ((*stack_a)->index != (*match).cheapest_a_index)
			rotate(stack_a, 'a');
	}
	else
	{
		while ((*stack_a)->index != (*match).cheapest_a_index)
			reverserotate(stack_a, 'a');
	}
}

void	bring_top_b(t_list **stack_b, t_match *match)
{	
	if ((*match).cheapest_b_pos <= (*match).len_stack_b / 2)
	{
		while ((*stack_b)->index != (*match).cheapest_b_index)
			rotate(stack_b, 'b');
	}
	else
	{
		while ((*stack_b)->index != (*match).cheapest_b_index)
			reverserotate(stack_b, 'b');
	}
}

void	bring_top_with_rr(t_list **stack_a, t_list **stack_b, t_match *match)
{
	while ((*stack_a)->index != (*match).cheapest_a_index
		&& (*stack_b)->index != (*match).cheapest_b_index)
		rotate_both(stack_a, stack_b);
	if ((*stack_a)->index != (*match).cheapest_a_index)
	{
		while ((*stack_a)->index != (*match).cheapest_a_index)
			rotate(stack_a, 'a');
	}
	else
	{
		while ((*stack_b)->index != (*match).cheapest_b_index)
			rotate(stack_b, 'b');
	}
}

void	bring_top_with_rrr(t_list **stack_a, t_list **stack_b, t_match *match)
{
	while ((*stack_a)->index != (*match).cheapest_a_index
		&& (*stack_b)->index != (*match).cheapest_b_index)
		reverserotate_both(stack_a, stack_b);
	if ((*stack_a)->index != (*match).cheapest_a_index)
	{
		while ((*stack_a)->index != (*match).cheapest_a_index)
			reverserotate(stack_a, 'a');
	}
	else
	{
		while ((*stack_b)->index != (*match).cheapest_b_index)
			reverserotate(stack_b, 'b');
	}
}

void	bring_best_to_top(t_list **stack_a, t_list **stack_b, t_match *match)
{
	int	long_stack_a;
	int	long_stack_b;
	int	rr;
	int	rrr;

	long_stack_a = (*match).len_stack_a != 1;
	long_stack_b = (*match).len_stack_b != 1;
	rr = (((*match).cheapest_a_pos <= ((*match).len_stack_a / 2))
			&& (((*match).cheapest_b_pos <= ((*match).len_stack_b / 2))));
	rrr = (((*match).cheapest_a_pos > ((*match).len_stack_a / 2))
			&& ((*match).cheapest_b_pos > ((*match).len_stack_b / 2)));
	if (long_stack_a == 1 && long_stack_b == 1 && (rr == 1 || rrr == 1))
	{
		if (rr == 1)
			bring_top_with_rr(stack_a, stack_b, match);
		else if (rrr == 1)
			bring_top_with_rrr(stack_a, stack_b, match);
	}
	else
	{
		if (long_stack_a)
			bring_top_a(stack_a, match);
		if (long_stack_b)
			bring_top_b(stack_b, match);
	}
}
