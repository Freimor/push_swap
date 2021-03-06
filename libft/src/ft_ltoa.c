/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:15:50 by sskinner          #+#    #+#             */
/*   Updated: 2020/04/07 17:15:49 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		itoa_isnegative(long *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char			*ft_ltoa(long n)
{
	long	tmpn;
	long	len;
	int		negative;
	char	*str;

	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	tmpn = n;
	len = 2;
	negative = 0;
	itoa_isnegative(&n, &negative);
	while (tmpn /= 10)
		len++;
	len += negative;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
