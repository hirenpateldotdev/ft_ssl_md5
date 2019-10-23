/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:31:11 by hirenpat          #+#    #+#             */
/*   Updated: 2018/12/17 15:31:22 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	const char *lg;
	const char *sm;

	if (*to_find == '\0')
		return ((char*)str);
	while (*str != '\0')
	{
		lg = str;
		sm = to_find;
		while (*sm != '\0' && *lg == *sm)
		{
			lg++;
			sm++;
		}
		if (*sm == '\0')
			return ((char*)str);
		str++;
	}
	return (NULL);
}
