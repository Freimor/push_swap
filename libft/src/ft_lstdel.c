/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:16:26 by sskinner          #+#    #+#             */
/*   Updated: 2020/04/07 17:14:45 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void*, size_t))
{
	t_list *tmp;

	if (!alst)
		return ;
	if (!del)
		return ;
	while (*alst)
	{
		tmp = *alst;
		(*alst) = (*alst)->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = NULL;
	}
	*alst = NULL;
}
