/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:48:00 by hirenpat          #+#    #+#             */
/*   Updated: 2019/05/22 16:48:04 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int					mod_handler(t_pf *cache, va_list args)
{
	char			c;

	(void)args;
	c = '%';
	if (cache->width && !cache->minus)
	{
		if (cache->zero)
			ft_putnchar('0', cache->width - 1);
		else
			ft_putnchar(' ', cache->width - 1);
	}
	write(1, &c, 1);
	if (cache->width && cache->minus)
		ft_putnchar(' ', cache->width - 1);
	return (cache->width ? cache->width : 1);
}

int					c_handler(t_pf *cache, va_list args)
{
	char			c;

	c = va_arg(args, int);
	if (cache->width && !cache->minus)
	{
		if (cache->zero)
			ft_putnchar('0', cache->width - 1);
		else
			ft_putnchar(' ', cache->width - 1);
	}
	write(1, &c, 1);
	if (cache->width && cache->minus)
	{
		if (cache->zero)
			ft_putnchar('0', cache->width - 1);
		else
			ft_putnchar(' ', cache->width - 1);
	}
	return (cache->width ? cache->width : 1);
}

int					s_handler(t_pf *cache, va_list args)
{
	char			*str;
	int				len;

	str = va_arg(args, char*);
	str = str ? str : "(null)";
	len = ft_strlen(str);
	if (len && cache->precision >= 0)
		len = MIN(len, cache->precision);
	if (cache->width && len < cache->width && !cache->minus)
	{
		if (cache->zero)
			ft_putnchar('0', cache->width - len);
		if (!cache->zero)
			ft_putnchar(' ', cache->width - len);
	}
	write(1, str, len);
	if (cache->width && len < cache->width && cache->minus)
		ft_putnchar(' ', cache->width - len);
	return (MAX(cache->width, len));
}

int					d_handler(t_pf *cache, va_list args)
{
	char			*str;
	long long int	nb;
	int				len;
	int				ret;

	nb = get_signed_int(cache, args);
	cache->is_negative = IS_NEG(nb);
	cache->zero = cache->minus && cache->zero ? 0 : cache->zero;
	str = !cache->precision && !nb ? ft_strdup("") : ft_ullitoa(ULLI(ABS(nb)));
	len = !cache->precision && !nb ? 0 : ft_strlen(str);
	ret = MAX(cache->precision, len);
	ret += cache->space || cache->plus || cache->is_negative ? 1 : 0;
	if (!cache->minus)
		padding(cache, len, ' ', ret);
	write_sign(cache);
	padding(cache, len, '0', ret);
	write(1, str, len);
	if (cache->minus)
		padding(cache, len, ' ', ret);
	free(str);
	return (cache->width > ret ? cache->width : ret);
}

int					u_handler(t_pf *cache, va_list args)
{
	char			*str;
	long long int	nb;
	int				len;
	int				ret;

	nb = get_unsigned_int(cache, args);
	cache->zero = cache->minus && cache->zero ? 0 : cache->zero;
	str = !cache->precision && !nb ? ft_strdup("") : ft_ullitoa(ULLI(nb));
	str = nb < 0 ? ft_strset(&str, "4294967295") : str;
	len = !cache->precision && !nb ? 0 : ft_strlen(str);
	ret = MAX(cache->precision, len);
	if (!cache->minus)
		padding(cache, len, ' ', ret);
	padding(cache, len, '0', ret);
	write(1, str, len);
	if (cache->minus)
		padding(cache, len, ' ', ret);
	free(str);
	return (cache->width > ret ? cache->width : ret);
}
