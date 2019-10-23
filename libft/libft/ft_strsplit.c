/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:30:54 by hirenpat          #+#    #+#             */
/*   Updated: 2018/12/17 15:30:58 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		strsplit_len(const char *s, char d)
{
	int			len;

	len = 0;
	while (*s != '\0' && *s != d)
	{
		len++;
		s++;
	}
	return (len);
}

static int		strsplit_count(const char *s, char d)
{
	int			position;
	int			nb;

	position = 0;
	nb = 0;
	while (*s != '\0')
	{
		if (*s != d && position == 0)
		{
			position = 1;
			nb++;
		}
		if (*s == d && position == 1)
			position = 0;
		s++;
	}
	return (nb);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**str;
	int			wd;
	int			i;

	i = 0;
	if (!s)
		return (0);
	wd = strsplit_count(s, c);
	str = (char**)malloc(sizeof(*str) * (strsplit_count(s, c) + 1));
	if (str == NULL)
		return (NULL);
	while (wd > 0)
	{
		while (*s == c && *s != '\0')
			s++;
		str[i] = ft_strsub(s, 0, strsplit_len(s, c));
		if (str[i] == NULL)
			return (NULL);
		s = s + strsplit_len(s, c);
		i++;
		wd--;
	}
	str[i] = NULL;
	return (str);
}
