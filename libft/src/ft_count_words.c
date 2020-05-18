/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:38:44 by sskinner          #+#    #+#             */
/*   Updated: 2020/04/07 17:06:05 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(char const *s)
{
	int		count;
	int		i;

	if (!s)
		return (0);
	count = 0;
	if (!ft_isspace(s[0]) && s[0] != '\0')
		count++;
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isspace(s[i]) && !ft_isspace(s[i + 1]) && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}
