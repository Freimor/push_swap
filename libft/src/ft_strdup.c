/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:40:08 by ojessi            #+#    #+#             */
/*   Updated: 2020/04/07 22:46:57 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*new;
	int		i;
	int		l;

	i = 0;
	while (str[i] != '\0')
		i++;
	new = (char *)malloc(sizeof(char) * (i + 1));
	if (new)
	{
		l = -1;
		while (++l < i)
			new[l] = str[l];
		new[l] = '\0';
	}
	return (new);
}