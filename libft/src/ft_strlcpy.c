/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:36:45 by sskinner          #+#    #+#             */
/*   Updated: 2020/04/08 09:53:42 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *source, size_t n)
{
	size_t	i;
	int		l;

	if (!source || !dest)
		return (0);
	if (n == 0)
	{
		n = ft_strlen(dest) + 1;
		dest[n] = '\0';
		return (ft_strlen(source));
	}
	i = 0;
	l = 0;
	while (dest[l] != '\0')
		l++;
	while (source[i] != '\0' && i < n - 1)
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	i = 0;
	while (source[i] != '\0')
		i++;
	return (i);
}
