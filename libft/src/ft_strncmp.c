/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:58:04 by sskinner          #+#    #+#             */
/*   Updated: 2020/04/08 09:54:21 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	i = 0;
	if (!n)
		return (0);
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n - 1)
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	if ((unsigned char)str1[i] != (unsigned char)str2[i])
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	return (0);
}
