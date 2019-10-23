/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:30:43 by hirenpat          #+#    #+#             */
/*   Updated: 2018/12/17 15:30:46 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == (char)c)
			return ((char*)s + i);
		i--;
	}
	if (s[i] == (char)c)
		return ((char*)s + i);
	return (NULL);
}

int		ft_arrchr(char **array, int array_len, char *find)
{
	int	i;

	i = -1;
	while (++i < array_len)
	{
		if (ft_strcmp(array[i], find) == 0)
			return (i);
	}
	return (-1);
}
