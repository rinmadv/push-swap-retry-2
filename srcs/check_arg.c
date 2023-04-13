/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:24:48 by marine            #+#    #+#             */
/*   Updated: 2023/04/13 23:49:15 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

bool	checkdup(t_list	*stack_a, long nb)
{
	while (stack_a)
	{
		if (nb == stack_a->content)
			return (true);
		else
			stack_a = stack_a->next;
	}
	return (false);
}

int	check_argv(int argc, char **argv, t_list **stack_a)
{
	int			i;
	long		nb;
	t_list		*list2;
	int			nb_digit;

	i = 1;
	while (i < argc)
	{
		nb_digit = countdigit(argv[i]);
		if ((nb_digit > 10 || nb_digit < 1))
			return (ft_lstclear(stack_a), -1);
		nb = ft_atol(argv[i]);
		if (nb >= INT_MIN && nb <= INT_MAX && checkdup(*stack_a, nb) == false)
		{
			list2 = ft_lstnew(nb);
			if (list2 == NULL)
				return (ft_lstclear(stack_a), -1);
			ft_lstadd_back(stack_a, list2);
			i++;
		}
		else
			return (ft_lstclear(stack_a), -1);
	}
	return (0);
}

int	is_sorted(t_list *stack_a)
{
	while (stack_a && stack_a->next != 0)
	{
		if (stack_a->content < stack_a->next->content)
			stack_a = stack_a->next;
		else
			return (0);
	}
	return (1);
}
