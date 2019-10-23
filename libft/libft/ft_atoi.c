/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:17:06 by hirenpat          #+#    #+#             */
/*   Updated: 2018/12/17 14:17:12 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	atoi_strdigit(char const *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

static char	*atoi_skipwhite(char const *str)
{
	while (IS_SP(*str))
		str++;
	return ((char*)str);
}

static int	atoi_isminus(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

static int	atoi_checklimits(char const *str)
{
	int		negative;
	char	*strmin;
	char	*strmax;

	strmin = "-922337203685477580820";
	strmax = "9223372036854775807";
	str = atoi_skipwhite(str);
	negative = atoi_isminus(*str);
	if (negative == -1)
	{
		if (atoi_strdigit(str) > 20)
			return (0);
		if (atoi_strdigit(str) == 20 && ft_strcmp(str, strmin) > 0)
			return (0);
	}
	if (negative == 1)
	{
		if (atoi_strdigit(str) > 19)
			return (-1);
		if (atoi_strdigit(str) == 19 && ft_strcmp(str, strmax) > 0)
			return (-1);
	}
	return (1);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		value;
	int		negative;

	if (atoi_checklimits(str) == -1 || atoi_checklimits(str) == 0)
		return (atoi_checklimits(str));
	negative = 1;
	i = 0;
	value = 0;
	while (IS_SP(str[i]))
		i++;
	if (str[i] == '-')
	{
		negative = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	else
		negative = 1;
	while (ft_isdigit(str[i]))
		value = value * 10 + (str[i++] - '0');
	return (value * negative);
}
