/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:58:35 by sskinner          #+#    #+#             */
/*   Updated: 2020/04/07 17:10:21 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (1);
	else if (ch >= 'A' && ch <= 'Z')
		return (1);
	else
		return (0);
}
