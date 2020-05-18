/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:57:54 by sskinner          #+#    #+#             */
/*   Updated: 2020/04/07 22:40:52 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t count)
{
	unsigned char		*d;
	const unsigned char	*s;
	const unsigned char	*lasts;
	unsigned char		*lastd;

	d = dest;
	s = source;
	lastd = d + (count - 1);
	lasts = s + (count - 1);
	if (d < s)
		while (count-- > 0)
			*d++ = *s++;
	else
		while (count-- > 0)
			*lastd-- = *lasts--;
	return (dest);
}
