/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:21:54 by hirenpat          #+#    #+#             */
/*   Updated: 2019/05/22 17:21:56 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

long long int				get_signed_int(t_pf *cache, va_list arg)
{
	if (cache->length == LL)
		return (va_arg(arg, long long int));
	if (cache->length == L)
		return (va_arg(arg, long int));
	if (cache->length == HH)
		return ((char)va_arg(arg, int));
	if (cache->length == H)
		return (short int)(va_arg(arg, int));
	if (cache->length == J)
		return (va_arg(arg, intmax_t));
	if (cache->length == Z)
		return (va_arg(arg, size_t));
	return ((int)va_arg(arg, int));
}

unsigned long long int		get_unsigned_int(t_pf *cache, va_list arg)
{
	if (cache->specifier == 'p')
		return (va_arg(arg, unsigned long long int));
	if (cache->length == LL)
		return (va_arg(arg, unsigned long long int));
	if (cache->length == L)
		return (va_arg(arg, unsigned long int));
	if (cache->length == HH)
		return ((unsigned char)va_arg(arg, unsigned int));
	if (cache->length == H)
		return ((unsigned short)va_arg(arg, unsigned int));
	if (cache->length == J)
		return (va_arg(arg, uintmax_t));
	if (cache->length == Z)
		return (va_arg(arg, size_t));
	return ((unsigned int)va_arg(arg, unsigned int));
}

long double					get_double_int(t_pf *cache, va_list arg)
{
	if (cache->length == UL)
		return (va_arg(arg, long double));
	return (va_arg(arg, double));
}

int							write_sign(t_pf *cache)
{
	char sign;

	if (cache->space)
		sign = ' ';
	if (cache->plus)
		sign = '+';
	if (cache->is_negative)
		sign = '-';
	if (cache->plus || cache->space || cache->is_negative)
	{
		write(1, &sign, 1);
		return (1);
	}
	return (0);
}

void						padding(t_pf *cache, int len, char c, int ret)
{
	if (c == 48)
	{
		if (cache->precision != -1)
			ft_putnchar('0', cache->precision > len ?
						cache->precision - len : 0);
		else if (cache->zero && cache->width)
			ft_putnchar('0', cache->width > ret ? cache->width - ret : 0);
	}
	else
	{
		if (cache->precision > -1 && cache->precision < len)
			cache->precision = len;
		if (!cache->zero && (cache->width > ret) && c == 32)
			ft_putnchar(' ', cache->width - ret);
		else if (cache->precision > -1 && (cache->width > cache->precision))
			ft_putnchar(' ', cache->width - cache->precision -
			(cache->plus || cache->space || cache->is_negative));
	}
}
