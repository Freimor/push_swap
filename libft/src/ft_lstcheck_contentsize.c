/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcheck_contentsize.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:06:42 by sskinner          #+#    #+#             */
/*   Updated: 2020/04/08 10:05:46 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcheck_contentsize(t_list **alst, size_t size)
{
	t_list	*ptr;

	ptr = *alst;
	while (ptr)
	{
		if (ptr->content_size == size)
			return (ptr);
		ptr = ptr->next;
	}
	return (0);
}