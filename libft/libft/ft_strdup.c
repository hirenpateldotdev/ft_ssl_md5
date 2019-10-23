/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:52:44 by hirenpat          #+#    #+#             */
/*   Updated: 2018/12/17 14:52:47 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*d;
	int		i;

	i = 0;
	d = (char *)malloc(ft_strlen(s1) + 1);
	if (d == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		d[i] = s1[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
