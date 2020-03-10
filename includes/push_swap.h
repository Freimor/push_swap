/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:52:42 by sskinner          #+#    #+#             */
/*   Updated: 2020/03/10 13:51:09 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/includes/libft.h"
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef enum
{
	false,
	true
}	t_bool;

typedef	struct	s_command
{
	char			*name;
	struct s_command	*next;
}				t_command;

typedef	struct	s_list_command
{
	int				size;
	struct s_command	*head;
}				t_list_command;

typedef	struct	s_stack
{
	int				num;
	int				index;
	t_bool			keep_in;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_list_stack
{
	int				size;
	struct s_stack	*head;
}				t_list_stack;

//list_actions
void			list_add2head(t_list_stack *list, t_stack *node, t_bool copy);
void			list_add2tail(t_list_stack *list, t_stack *node, t_bool copy);
void			list_cut(t_list_stack *list, t_stack *cut_node, t_bool delete);
t_list_stack	*list_copylist(t_list_stack *old);
void			list_deleteall(t_list_stack *list);
t_stack			*stack_copystack(t_stack *stack, t_bool save_next);
t_list_stack	*list_sort_ascending(t_list_stack *list);
void			set_index(t_list_stack *sortlist);
t_stack			*list_apply_index(t_list_stack *dst, t_list_stack *src);


//solve_actions
void			markup(t_list_stack *list, t_bool indexing);
//solve
void			solve_first(t_list_stack *a, t_list_stack *b, t_list_command *command, t_bool first);
void			solve_1(t_list_stack *a);

//command actions
void			add_command(t_list_command *list_commands, char *command);
t_bool			sa_needed(t_list_stack *list);


//commands
void			sa(t_list_stack *a, t_list_command *list_command, t_bool mark);
void			pa(t_list_stack *a, t_list_stack *b, t_list_command *list_command);
void			ra(t_list_stack *a, t_list_command *list_command);
void			rra(t_list_stack *a, t_list_command *list_command);
void			sb(t_list_stack *b, t_list_command *list_command, t_bool mark);
void			pb(t_list_stack *a, t_list_stack *b, t_list_command *list_command);
void			rb(t_list_stack *b, t_list_command *list_command);
void			rrb(t_list_stack *b, t_list_command *list_command);
void			ss(t_list_stack *a, t_list_stack *b, t_list_command *list_command);
void			rr(t_list_stack *a, t_list_stack *b, t_list_command *list_command);
void			rrr(t_list_stack *a, t_list_stack *b, t_list_command *list_command);

//print
void			print_list(t_list_stack *list, t_bool with_index, t_bool with_mark);
void			print_commands(t_list_command *command);

#endif // !PUSH_SWAP_H