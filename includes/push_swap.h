/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:52:42 by sskinner          #+#    #+#             */
/*   Updated: 2020/04/05 21:12:26 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
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
	char					*name;
	struct s_command		*next;
}							t_command;

typedef	struct	s_list_command
{
	int						size;
	struct s_command		*head;
}							t_list_command;

typedef	struct	s_stack
{
	int						num;
	int						index;
	t_bool					flag;
	struct s_list_command	*comand_list;
	struct s_stack			*next;
}							t_stack;

typedef struct	s_list_stack
{
	int						size;
	struct s_stack			*head;
}							t_list_stack;

/*| command_actions.c |*/
/*Add command to list of commands*/
void			command_add(t_list_command *list_commands, char *command);
/*| command_actions.c |*/
/*Delete command in list of commands*/
void			command_delete(t_list_command *list_commands, char *command);
/*| command_actions.c |*/
/*Replace ra and rb (or rra and rrb) to rr (rrr)*/
void			double_command_update(t_stack *stack, t_bool flag);
/*| command_additionals.c |*/
/*Clean local lists of commands*/
void			clean_commands(t_list_stack *b);
/*| command_additionals.c |*/
/*Clean list of commands*/
void			command_list_delete(t_list_command *command);
/*| command_additionals.c |*/
/*Copy sub command list to new copy of stack elem*/
void			command_locallist(t_stack *stack, t_list_command *command);
/*| command_additionals.c |*/
/*Copy list of commands*/
t_list_command	*command_list_copy(t_list_command *list);
/*| command_additionals.c |*/
/*If command in list -> return true, else false*/
t_bool			find_command(t_list_command *list, char *command);
/*| input_checker.c |*/
/*Forming first stack and check for duplicates*/
t_bool			check_listfordup(t_list_stack *list, int ac, char **arg);
/*| input_checker.c |*/
/*Check arguments*/
t_bool			input_checker(int ac, char **arg);
/*| input_checker.c |*/
/*Check input for numbers*/
int				input_check_number(char *array);
/*| list_actions_1.c |*/
/*Add the stack to the head of the list*/
void			list_add2head(t_list_stack *list, t_stack *node, t_bool copy);
/*| list_actions_1.c |*/
/*Add the stack to the end of the list*/
void			list_add2tail(t_list_stack *list, t_stack *node, t_bool copy);
/*| list_actions_1.c |*/
/*Cut stack in list (delete == true -> delete this stack (free)*/
void			list_cut(t_list_stack *list, t_stack *cut_node, t_bool delete);
/*| list_actions_1.c |*/
/*Copy list*/
t_list_stack	*list_copylist(t_list_stack *old);
/*| list_actions_1.c |*/
/*Compleet list deletion*/
void			list_deleteall(t_list_stack *list, t_bool form_first_list);
/*| list_actions_2.c |*/
/*Form first stack*/
void			form_first_list(t_list_stack *list, int num);
/*| list_actions_2.c |*/
/*Check raw list for duplicates*/
t_bool			list_checkduplicate(t_list_stack *list);
/*| list_additionals.c |*/
/*Copy stack*/
t_stack			*stack_copystack(t_stack *stack);
/*| list_additionals.c |*/
/*Length of list*/
int				list_len(t_list_stack *list);
/*| list_additionals.c |*/
/*Search stack in list*/
t_stack			*find_stack(t_list_stack *list, int index);
/*| list_indexing.c |*/
/*Indexation in ascending order*/
void			list_indexing(t_list_stack *list);
/*| operation_list_a.c |*/
/*swap a - swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements).*/
void			sa(t_list_stack *a, t_list_command *list_command);
/*| operation_list_a.c |*/
/*push a - take the first element at the top of b and put it at the top of a.
Do nothing if a is empty.*/
void			pa(t_list_stack *a, t_list_stack *b, t_list_command *list_command);
/*| operation_list_a.c |*/
/*rotate a - shift up all elements of stack a by 1.
The first element becomes the last one.*/
void			ra(t_list_stack *a, t_list_command *list_command);
/*| operation_list_a.c |*/
/*reverse rotate a - shift down all elements of stack a by 1.
The last element becomes the first one.*/
void			rra(t_list_stack *a, t_list_command *list_command);
/*| operation_list_b.c |*/
/*swap b - swap the first 2 elements at the top of stack b. 
Do nothing if there is only one or no elements).*/
void			sb(t_list_stack *b, t_list_command *list_command);
/*| operation_list_b.c |*/
/*push b - take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.*/
void			pb(t_list_stack *a, t_list_stack *b, t_list_command *list_command);
/*| operation_list_b.c |*/
/*rotate a - shift up all elements of stack a by 1.
The first element becomes the last one.*/
void			rb(t_list_stack *b, t_list_command *list_command);
/*| operation_list_b.c |*/
/*reverse rotate b - shift down all elements of stack b by 1. 
The last element becomes the first one.*/
void			rrb(t_list_stack *b, t_list_command *list_command);
/*| operation_list_ab.c |*/
/*sa and sb at the same time.*/
void			ss(t_list_stack *a, t_list_stack *b, t_list_command *list_command);
/*| operation_list_ab.c |*/
/*ra and rb at the same time.*/
void			rr(t_list_stack *a, t_list_stack *b, t_list_command *list_command);
/*| operation_list_ab.c |*/
/*rra and rrb at the same time.*/
void			rrr(t_list_stack *a, t_list_stack *b, t_list_command *list_command);
/*| print_additionals_1.c |*/
/*Print to consol list of stack (with_index == true -> print with index).*/
void			print_list(t_list_stack *list, t_bool with_index);
/*| print_additionals_1.c |*/
/*Print list of commands.*/
void			print_commands(t_list_command *command);
/*| solve_additionals_1.c |*/
/*Choosing a more effective command.*/
t_bool			rb_or_rrb(t_list_stack *b, int index);
/*| solve_additionals_1.c |*/
/*Checking for the correct order of elements.*/
/*(rigor == true -> stack->index + 1 = stack->next->index).*/
t_bool			check_align(t_list_stack *list, t_bool rigor);
/*| solve_additionals_1.c |*/
/*Search for the closest index.*/
int				find_closest_index(t_list_stack *a, int index);
/*| solve_additionals_1.c |*/
/*ra or rra while index = 0 not in head of list*/
void			zero_to_head(t_list_stack *a, t_list_command *command);
/*| solve_additionals_2.c |*/
/*Execute commands sublist*/
void			exec_command_list(t_list_command *local, t_list_command *command, t_list_stack *a, t_list_stack *b);
/*| solve_additionals_2.c |*/
/*Correction main command list*/
void			command_list_correction(t_list_command *command);
/*| solve_algoritm_1.c |*/
/*| Detect sorted elements and push not sorted elements to stack b |*/
void			solve_first(t_list_stack *a, t_list_stack *b, t_list_command *command);
/*| solve_algoritm_2.c |*/
/*Solver*/
void			solve(t_list_stack *a, t_list_command *command);
/*| push_swap_additionals.c |*/
/*Print error message and close exec*/
void			crash(char *str);
/*| push_swap_additionals.c |*/
/*Full input validation*/
t_list_stack	*input_fabrication(int ac, char **arg);
/*| push_swap_additionals.c |*/
/*Main push swap algoritm. Return list of commands*/
t_list_command	*push_swap(t_list_stack *list);

#endif // !PUSH_SWAP_H