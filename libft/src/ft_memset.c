/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:14:26 by sskinner          #+#    #+#             */
/*   Updated: 2020/04/07 22:41:01 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int value, size_t num)
{
	unsigned char *str;

	str = memptr;
	while (num-- > 0)
		*str++ = value;
	return (memptr);
}
