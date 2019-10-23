/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:56:10 by hirenpat          #+#    #+#             */
/*   Updated: 2018/12/17 14:56:13 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	const char	*lg;
	const char	*sm;
	size_t		i;

	if (*to_find == '\0')
		return ((char*)str);
	while (*str != '\0' && len > 0)
	{
		lg = str;
		sm = to_find;
		i = len;
		while (*sm != '\0' && *lg == *sm && i--)
		{
			lg++;
			sm++;
		}
		if (*sm == '\0')
			return ((char*)str);
		str++;
		--len;
	}
	return (NULL);
}
