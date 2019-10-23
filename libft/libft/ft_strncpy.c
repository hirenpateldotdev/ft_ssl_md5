/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:55:37 by hirenpat          #+#    #+#             */
/*   Updated: 2018/12/17 14:55:39 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while ((len > i) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	while (len > i)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
