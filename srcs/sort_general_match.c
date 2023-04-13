/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general_match.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:24:48 by marine            #+#    #+#             */
/*   Updated: 2023/04/11 00:08:14 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

bool	better_match(t_list	*stack_a, t_list *stack_b, int current_match)
{
	int	current_node_a;
	int	current_node_b;
	int	diff_current_match;
	int	diff_possible_match;

	current_node_a = stack_a->index;
	current_node_b = stack_b->index;
	if (current_node_a < current_node_b)
		return (false);
	diff_current_match = abs(current_match - current_node_b);
	diff_possible_match = abs(current_node_a - current_node_b);
	if (diff_current_match < diff_possible_match)
		return (false);
	else
		return (true);
}

void	match_cost(t_match *match)
{
	int	match_a_cost;
	int	match_b_cost;

	if (match->pos_a <= match->len_stack_a / 2 || match->pos_a == 1)
		match_a_cost = match->pos_a - 1;
	else
		match_a_cost = match->len_stack_a - match->pos_a + 1;
	if (match->pos_b <= match->len_stack_b / 2 || match->pos_b == 1)
		match_b_cost = match->pos_b - 1;
	else
		match_b_cost = match->len_stack_b - match->pos_b + 1;
	match->cost = match_a_cost + match_b_cost;
}

void	get_match(t_list *stack_a, t_list *stack_b, t_match	*match)
{
	match->pos_a = 1;
	match->len_stack_a = 1;
	while (stack_a->index < stack_b->index)
	{
		stack_a = stack_a->next;
		match->pos_a++;
		match->len_stack_a++;
	}
	match->index_a = stack_a->index;
	while (stack_a->next != NULL)
	{
		stack_a = stack_a->next;
		match->len_stack_a++;
		if (better_match(stack_a, stack_b, match->index_a) == true)
		{
			match->index_a = stack_a->index;
			match->pos_a = match->len_stack_a;
		}
	}
}

void	match_nodes(t_list **stack_a, t_list **stack_b, t_match	*match)
{
	t_list	*temp;

	temp = *stack_b;
	match->cheapest_cost = INT_MAX;
	match->pos_b = 1;
	while ((*stack_b) != NULL)
	{
		get_match(*stack_a, *stack_b, match);
		match_cost(match);
		if (match->cheapest_cost > match->cost)
		{
			match->cheapest_a_index = match->index_a;
			match->cheapest_b_index = (*stack_b)->index;
			match->cheapest_a_pos = match->pos_a;
			match->cheapest_b_pos = match->pos_b;
			match->cheapest_cost = match->cost;
		}
		(*stack_b) = (*stack_b)->next;
		match->pos_b++;
	}
	*stack_b = temp;
	bring_best_to_top(stack_a, stack_b, match);
	push(stack_b, stack_a, 'a');
}
