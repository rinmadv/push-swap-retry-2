/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:59:32 by madavid           #+#    #+#             */
/*   Updated: 2023/04/11 21:37:54 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}				t_list;

typedef struct s_match
{
	int				index_b;
	int				pos_b;
	int				len_stack_b;
	int				index_a;
	int				pos_a;
	int				len_stack_a;
	int				size;
	int				cost;
	int				cheapest_a_pos;
	int				cheapest_b_pos;
	int				cheapest_a_index;
	int				cheapest_b_index;
	int				cheapest_cost;
}				t_match;

typedef struct s_top
{
	int				long_stack_a;
	int				long_stack_b;
	int				rr;
	int				rrr;
}				t_top;

/* Main */
int		sort_choice(t_list **stack_a, t_list **stack_b, int size);

/* Utils */
long	ft_atol(const char *str);
int		countdigit(const char *str);
void	ft_putnbr(int nbr);
int		abs(int x);

/* Check argv */
int		check_argv(int argc, char **argv, t_list **stack_a);
bool	checkdup(t_list	*stack_a, long nb);
int		is_sorted(t_list *stack_a);

/* Linked lists*/
t_list	*ft_lstnew(int contenu);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstbeforelast(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(int));

/* Operations */
void	swap(t_list *stack, char s);
void	swap_both(t_list *stack_a, t_list *stack_b);
void	push(t_list **takefrom, t_list **addto, char s);
void	rotate(t_list **stack, char s);
void	rotate_both(t_list **stack_a, t_list **stack_b);
void	reverserotate(t_list **stack, char s);
void	reverserotate_both(t_list **stack_a, t_list **stack_b);

/* Sort 2 & 3  & 5 */
int		find_pos_min(t_list *stack_a);
void	push_min(t_list **stack_a, t_list **stack_b, int size);
void	sort_two(t_list **stack_a);
void	sort_three(t_list **stack_a);
void	sort_five(t_list **stack_a, t_list **stack_b);

/* Sort 100 - 500 */
int		sort_general(t_list **stack_a, t_list **stack_b, int size);
void	bring_min_to_top(t_list **stack_a, int size);

/* Indexing & Presort*/

int		find_first_min(t_list *stack_a);
int		find_next_min(t_list *stack_a, int old_min);
void	indexing(t_list **stack_a, int size);
void	presort(t_list **stack_a, t_list **stack_b, int size);

/* Match nodes */
void	match_nodes(t_list **stack_a, t_list **stack_b, t_match *match);
void	get_match(t_list *stack_a, t_list *stack_b, t_match *match);
bool	better_match(t_list *stack_a, t_list *stack_b, int current_match);
void	match_cost(t_match *match);

/* Bring node to the top */
void	bring_best_to_top(t_list **stack_a, t_list **stack_b, t_match *match);
void	bring_top_with_rrr(t_list **stack_a, t_list **stack_b, t_match *match);
void	bring_top_with_rr(t_list **stack_a, t_list **stack_b, t_match *match);
void	bring_top_a(t_list **stack_a, t_match *match);
void	bring_top_b(t_list **stack_b, t_match *match);

#endif
