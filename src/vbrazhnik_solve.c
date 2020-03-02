/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vbrazhnik_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freimor <freimor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:48:43 by freimor           #+#    #+#             */
/*   Updated: 2020/02/29 16:48:45 by freimor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_bool	check_keepin(t_list_stack *list)
{
	t_stack	*stack;

	stack = list->head;
	while (stack != NULL)
	{
		if (stack->keep_in == false)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	solve_first(t_list_stack *a, t_list_stack *b, t_list_comand *command)
{
	/*WHILE stack A has elements with "false" value in "Keep in Stack A" field
      IF sa (swap a) is needed
            perform sa (swap a) command
            update markup
      ELSE IF head element of stack A has "false" value in "Keep in Stack A" field
            perform pb (push b) command
      ELSE
            perform ra (rotate a) command*/
	t_stack	*stack_a;

	stack_a = a->head;
	while (check_keepin(a) == false)
	{
		if (sa_needed == true)
			sa(a, command, true);
		else if (a->head->keep_in == false)
			pb(a, b, command);
		else
			ra(a, command);
	}
}

void	solve_second(t_list_stack *a, t_list_stack *b, t_list_comand *command)
{
	/*WHILE stack B is not empty
      choose element in stack B for moving to stack A
      move stack A and stack B to prepare them for pa (push a) with chosen element
      perform pa (push a) command*/
	  while (b->head != NULL)
	  {
		  
	  }
}