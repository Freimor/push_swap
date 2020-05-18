/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:40:19 by sskinner          #+#    #+#             */
/*   Updated: 2020/04/07 17:14:32 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **alst, t_list *new)
{
	t_list *list;

	if (!alst)
		return ;
	list = *alst;
	if (*alst)
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
	else
		*alst = new;
}
