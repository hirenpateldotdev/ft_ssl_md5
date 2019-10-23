/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:19:31 by hirenpat          #+#    #+#             */
/*   Updated: 2018/12/19 17:16:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		num_size(unsigned int num)
{
	unsigned int	size;

	size = 0;
	while (num >= 10)
	{
		num /= 10;
		++size;
	}
	return (size + 1);
}

char			*ft_itoa(int nbr)
{
	char			*str;
	unsigned int	num;
	unsigned int	i;
	unsigned int	size;

	if (nbr < 0)
		num = (unsigned int)(nbr * -1);
	else
		num = (unsigned int)nbr;
	size = (unsigned int)num_size(num);
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1 + (nbr < 0 ? 1 : 0)))))
		return (0);
	if (nbr < 0 && (str[i] = '-'))
		size++;
	i = size - 1;
	while (num >= 10)
	{
		str[i--] = (char)(num % 10 + 48);
		num /= 10;
	}
	str[i] = (char)(num % 10 + 48);
	str[size] = '\0';
	return (str);
}
