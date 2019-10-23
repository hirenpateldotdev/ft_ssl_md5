/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_extra_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:22:03 by hirenpat          #+#    #+#             */
/*   Updated: 2019/05/22 17:22:07 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int					ft_place_value(unsigned long long int nb, int base)
{
	int				count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		++count;
		nb /= base;
	}
	return (count);
}

char				*ft_ullitoa(unsigned long long int nb)
{
	int				len;
	char			*str;

	len = ft_place_value(nb, 10);
	str = malloc(sizeof(int) * (len + 1));
	str[len] = 0;
	if (nb == 0)
		str[0] = '0';
	while (nb)
	{
		len--;
		str[len] = (nb % 10) + 48;
		nb /= 10;
	}
	return (str);
}

char				*ft_ullitoa_base(unsigned long long int nb,
					int base, char s)
{
	int				len;
	char			*str;

	len = ft_place_value(nb, base);
	str = malloc(sizeof(int) * (len + 1));
	str[len] = 0;
	if (nb == 0)
		str[0] = '0';
	while (nb)
	{
		len--;
		if ((nb % base) > 9)
			str[len] = (nb % base - 10 + s);
		else
			str[len] = (nb % base) + '0';
		nb /= base;
	}
	return (str);
}

char				*ft_llitoa(long long int nb)
{
	int				len;
	char			*str;
	int				is_neg;

	is_neg = IS_NEG(nb);
	len = ft_place_value(ABS(nb), 10);
	str = malloc(sizeof(int) * (len + 1 + is_neg));
	str[len] = 0;
	if (nb == 0)
		str[0] = '0';
	while (ABS(nb))
	{
		len--;
		str[len] = (ABS(nb) % 10) + 48;
		nb /= 10;
	}
	if (is_neg)
		str[0] = '-';
	return (str);
}

char				*ft_ldtoa(long double f_nb, int precision)
{
	char			*result;
	char			*decimal;
	long double		fraction;
	int				i;

	result = ft_llitoa((long)f_nb);
	precision = precision < 0 ? 6 : precision;
	if (precision != 0)
	{
		result = ft_strjoinf(result, ".");
		fraction = f_nb - (long)f_nb;
		i = 0;
		decimal = ft_strnew(precision);
		while (i < precision)
		{
			fraction = fraction * 10;
			decimal[i] = ((long)fraction % 10) + '0';
			fraction = fraction - (long)fraction;
			i++;
		}
		result = ft_strjoinf(result, decimal);
		free(decimal);
	}
	return (result);
}
