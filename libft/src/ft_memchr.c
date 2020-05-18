/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:09:30 by sskinner          #+#    #+#             */
/*   Updated: 2020/04/07 22:39:32 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	char *str;

	str = (char*)arr;
	while (n--)
	{
		if (*(unsigned char*)str != (unsigned char)c)
			str++;
		else
			return (str);
	}
	return (NULL);
}
