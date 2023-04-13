/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:24:48 by marine            #+#    #+#             */
/*   Updated: 2023/04/11 22:02:46 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sort_choice(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
		sort_two(stack_a);
	if (size == 3)
		sort_three(stack_a);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
	{
		if (sort_general(stack_a, stack_b, size) == -1)
			return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_list;

	stack_a = NULL;
	stack_b = NULL;
	size_list = argc - 1;
	if (size_list == 0)
		return (0);
	if (check_argv(argc, argv, &stack_a) == -1)
		return (write(2, "Error\n", 6));
	if (size_list == 1)
		return (ft_lstclear(&stack_a), 0);
	if (is_sorted(stack_a) == 1)
		return (ft_lstclear(&stack_a), 0);
	if (sort_choice(&stack_a, &stack_b, size_list) == -1)
		return (write(2, "Error\n", 6));
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
