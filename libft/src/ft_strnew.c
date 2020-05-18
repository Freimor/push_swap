/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:41:58 by sskinner          #+#    #+#             */
/*   Updated: 2020/04/08 09:54:41 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	ptr = NULL;
	ptr = (char*)malloc(sizeof(char) * (size + 1));
	if (ptr)
		return ((char*)ft_memset(ptr, '\0', size + 1));
	else
		return (NULL);
}
