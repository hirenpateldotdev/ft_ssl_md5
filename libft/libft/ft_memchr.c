/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:48:04 by hirenpat          #+#    #+#             */
/*   Updated: 2018/12/17 14:48:07 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		if (((unsigned char*)str)[i] == (unsigned char)c)
			return ((void*)(str + i));
		i++;
	}
	return (NULL);
}
