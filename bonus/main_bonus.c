/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:17:25 by madavid           #+#    #+#             */
/*   Updated: 2023/04/13 23:09:42 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

int	call_moves(char *move, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(move, "sa\n") == 0)
		swap(*stack_a, 'a');
	else if (ft_strcmp(move, "sb\n") == 0)
		swap(*stack_b, 'b');
	else if (ft_strcmp(move, "ss\n") == 0)
		swap_both(*stack_a, *stack_b);
	else if (ft_strcmp(move, "pa\n") == 0)
		push(stack_b, stack_a, 'a');
	else if (ft_strcmp(move, "pb\n") == 0)
		push(stack_a, stack_b, 'b');
	else if (ft_strcmp(move, "ra\n") == 0)
		rotate(stack_a, 'a');
	else if (ft_strcmp(move, "rb\n") == 0)
		rotate(stack_b, 'b');
	else if (ft_strcmp(move, "rr\n") == 0)
		rotate_both(stack_a, stack_b);
	else if (ft_strcmp(move, "rra\n") == 0)
		reverserotate(stack_a, 'a');
	else if (ft_strcmp(move, "rrb\n") == 0)
		reverserotate(stack_b, 'b');
	else if (ft_strcmp(move, "rrr\n") == 0)
		reverserotate_both(stack_a, stack_b);
	return (1);
}

int	check_instructions(char *move, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(move, "sa\n") == 0 || ft_strcmp(move, "sb\n") == 0
		|| ft_strcmp(move, "ss\n") == 0 || ft_strcmp(move, "pa\n") == 0
		|| ft_strcmp(move, "pb\n") == 0 || ft_strcmp(move, "ra\n") == 0
		|| ft_strcmp(move, "rb\n") == 0 || ft_strcmp(move, "rr\n") == 0
		|| ft_strcmp(move, "rra\n") == 0 || ft_strcmp(move, "rrb\n") == 0
		|| ft_strcmp(move, "rrr\n") == 0)
		return (call_moves(move, stack_a, stack_b));
	return (0);
}

int	do_moves(t_move **lst_move, t_list **st_a, t_list **st_b)
{
	t_move	*begin;

	begin = *lst_move;
	while (*lst_move)
	{
		if (check_instructions((*lst_move)->content, st_a, st_b) == 0)
		{
			ft_lstclear(st_a);
			ft_lstclear(st_b);
			*lst_move = begin;
			ft_moveclear(lst_move);
			return (-1);
		}
		*lst_move = (*lst_move)->next;
	}
	*lst_move = begin;
	return (0);
}

void	free_all(t_list **stack_a, t_list **stack_b, t_move **lst_move)
{
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	ft_moveclear(lst_move);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_move	*lst_move;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (check_argv(argc, argv, &stack_a) == -1)
		return (write(2, "Error\n", 6));
	lst_move = NULL;
	if (fill_lst_move(&lst_move) == -1)
		return (ft_lstclear(&stack_a), write(2, "Error\n", 6));
	if (do_moves(&lst_move, &stack_a, &stack_b) == -1)
		return (write(2, "Error\n", 6));
	if (!is_sorted(stack_a) || stack_b)
		return (free_all(&stack_a, &stack_b, &lst_move), write(2, "KO\n", 3));
	return (free_all(&stack_a, &stack_b, &lst_move), write(1, "OK\n", 3), 0);
}
