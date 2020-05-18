/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:54:36 by sskinner          #+#    #+#             */
/*   Updated: 2020/04/08 10:01:36 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int i;
	int	j;

	i = 0;
	if (!str2[0])
		return ((char*)str1);
	while (str1[i] != '\0')
	{
		j = 0;
		while (str2[j] != '\0' && str2[j] == str1[i + j] && str1[j + i] != '\0')
			j++;
		if (!str2[j])
			return ((char*)&str1[i]);
		i++;
	}
	return (NULL);
}
