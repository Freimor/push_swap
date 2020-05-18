/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:41:43 by sskinner          #+#    #+#             */
/*   Updated: 2020/04/08 09:53:33 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *source, size_t n)
{
	char		*d;
	const char	*s;
	size_t		dlen;
	size_t		siz;

	d = dest;
	s = source;
	siz = n;
	while (siz-- != 0 && *d != '\0')
		d++;
	dlen = d - dest;
	siz = n - dlen;
	if (siz == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (siz != 1)
		{
			*d++ = *s;
			siz--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - source));
}
