/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:55:28 by sskinner          #+#    #+#             */
/*   Updated: 2020/04/08 09:54:48 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (n == 0 && !ft_strcmp(str2, ""))
		return ((char*)str1);
	else if (n == 0)
		return (NULL);
	while (str1[i] != '\0' && i < n)
	{
		j = 0;
		while (str2[j] != '\0' && str2[j] == str1[i + j] &&
				str1[j + i] != '\0' && j + i < n)
			j++;
		if (str2[j] == '\0')
			return ((char*)&(str1[i]));
		i++;
	}
	return (NULL);
}
