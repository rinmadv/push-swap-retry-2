/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:59:32 by madavid           #+#    #+#             */
/*   Updated: 2023/04/11 20:25:06 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct s_move
{
	char			*content;
	struct s_move	*next;
}				t_move;

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}				t_list;

/* Main */
int		check_instructions(char *move, t_list **stack_a, t_list **stack_b);
int		call_moves(char *move, t_list **stack_a, t_list **stack_b);
int		do_moves(t_move **lst_move, t_list **st_a, t_list **st_b);

/* Utils */
long	ft_atol(const char *str);
int		countdigit(const char *str);
int		ft_strcmp(const char *s1, const char *s2);

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

/* Read moves */
t_move	*ft_movenew(char *contenu);
t_move	*ft_movelast(t_move *lst);
int		ft_moveadd_back(t_move **lst, char *new);
int		fill_lst_move(t_move **lst_move);
void	ft_moveclear(t_move **lst);

#endif
