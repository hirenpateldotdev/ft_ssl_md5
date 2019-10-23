/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:48:00 by hirenpat          #+#    #+#             */
/*   Updated: 2019/05/22 16:48:04 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int							o_handler(t_pf *cache, va_list args)
{
	unsigned long long int	nb;
	int						ret;
	int						len;
	char					*str_nb;

	nb = get_unsigned_int(cache, args);
	str_nb = ft_ullitoa_base(ULLI(nb), 8, '0');
	str_nb = !nb && !cache->precision ? ft_strset(&str_nb, "") : str_nb;
	if (cache->hashtag)
		cache->precision = !nb ? MAX(cache->precision, 1) :
	MAX(cache->precision, (int)(ft_strlen(str_nb) + 1));
	cache->zero = cache->precision >= 0 || cache->minus ? 0 : cache->zero;
	if (cache->hashtag)
		cache->precision = cache->precision >= 0 && cache->precision >
	(int)ft_strlen(str_nb) + 1 ? cache->precision : ft_strlen(str_nb) + 1;
	len = cache->precision && !nb ? 0 : ft_strlen(str_nb);
	ret = MAX(cache->precision, len);
	if (!cache->minus)
		padding(cache, len, ' ', ret);
	padding(cache, len, '0', ret);
	write(1, str_nb, len);
	if (cache->minus)
		padding(cache, len, ' ', ret);
	free(str_nb);
	return (cache->width > ret ? cache->width : ret);
}

int							no_case_x_handler(t_pf *cache, char *prefix,
							unsigned long long int nb, char *str_nb)
{
	int						len;
	int						ret;

	str_nb = nb == 0 ? ft_strset(&str_nb, "0") : str_nb;
	if (nb == 0 && cache->precision == 0)
		str_nb = ft_strset(&str_nb, "");
	len = cache->precision && !nb ? 1 : ft_strlen(str_nb);
	ret = MAX(cache->precision, len) + (cache->hashtag && nb ? 2 : 0);
	if (!cache->minus)
		padding(cache, len, ' ', ret);
	if (cache->hashtag && nb)
		write(1, prefix, 2);
	padding(cache, len, '0', ret);
	write(1, str_nb, len);
	if (cache->minus)
		padding(cache, len, ' ', ret);
	free(str_nb);
	return (cache->width > ret ? cache->width : ret);
}

int							x_handler(t_pf *cache, va_list args)
{
	unsigned long long int	nb;
	int						ret;
	char					*str_nb;

	ret = 0;
	nb = get_unsigned_int(cache, args);
	if (cache->minus && cache->zero)
		cache->zero = 0;
	if (cache->specifier == 'x')
	{
		str_nb = ft_ullitoa_base(nb, 16, 'a');
		ret = no_case_x_handler(cache, "0x", nb, str_nb);
		return (ret);
	}
	else if (cache->specifier == 'X')
	{
		str_nb = ft_ullitoa_base(nb, 16, 'A');
		ret = no_case_x_handler(cache, "0X", nb, str_nb);
		return (ret);
	}
	return (ret);
}

int							f_handler(t_pf *cache, va_list args)
{
	long double				f_nb;
	char					*result;
	int						len;

	f_nb = get_double_int(cache, args);
	result = ft_ldtoa((long double)f_nb, cache->precision);
	len = ft_strlen(result);
	if (len <= cache->width)
	{
		if (cache->zero == 1)
			ft_putnchar('0', cache->width - len);
		else if (cache->space == 1)
			ft_putnchar(' ', cache->width - len);
	}
	ft_putstr(result);
	free(result);
	return (MAX(len, cache->width));
}

int							p_handler(t_pf *cache, va_list args)
{
	unsigned long long int	nb;
	int						ret;
	int						len;
	char					*str_nb;

	nb = get_unsigned_int(cache, args);
	str_nb = ft_ullitoa_base(nb, 16, 'a');
	if (nb == 0)
		str_nb = ft_strset(&str_nb, "0");
	len = cache->precision && !nb ? 1 : ft_strlen(str_nb);
	ret = MAX(cache->precision, len) + 2;
	if (!cache->minus)
		padding(cache, len, ' ', ret);
	write(1, "0x", 2);
	padding(cache, len, '0', ret);
	write(1, str_nb, len);
	if (cache->minus)
		padding(cache, len, ' ', ret);
	free(str_nb);
	return (cache->width > ret ? cache->width : ret);
}
