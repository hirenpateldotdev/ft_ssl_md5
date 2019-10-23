/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:48:00 by hirenpat          #+#    #+#             */
/*   Updated: 2019/05/22 16:48:04 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int							b_handler(t_pf *cache, va_list args)
{
	unsigned long long int	nb;
	int						ret;
	int						len;
	char					*str_nb;

	nb = get_unsigned_int(cache, args);
	str_nb = ft_ullitoa_base(ULLI(nb), 2, '0');
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
