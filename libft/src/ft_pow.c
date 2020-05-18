/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:24:51 by sskinner          #+#    #+#             */
/*   Updated: 2020/04/07 22:41:32 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int nbr, int power)
{
	int		i;
	int		res;

	i = -1;
	res = 1;
	if (nbr == 0 && power == 0)
		return (1);
	else if (nbr == 0 && power != 0)
		return (0);
	while (++i < power)
		res *= nbr;
	return (res);
}
