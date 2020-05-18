/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 20:02:51 by sskinner          #+#    #+#             */
/*   Updated: 2020/04/08 10:01:44 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	int		j;

	if (!s)
		return (NULL);
	str = NULL;
	j = 0;
	i = 0;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str)
	{
		while (s[i] != '\0')
		{
			if (i >= start && i < len + start)
			{
				str[j] = s[i];
				j++;
			}
			i++;
		}
		str[j] = '\0';
	}
	return (str);
}
