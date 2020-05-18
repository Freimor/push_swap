/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:43:20 by sskinner          #+#    #+#             */
/*   Updated: 2020/04/07 22:39:00 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
		if (((unsigned char *)dst)[i - 1] == (unsigned char)c)
			return (&((unsigned char *)dst)[i]);
	}
	return (NULL);
}
