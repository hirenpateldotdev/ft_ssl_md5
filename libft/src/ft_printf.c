/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:13:40 by hirenpat          #+#    #+#             */
/*   Updated: 2019/03/11 20:13:43 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int					ft_printf(const char *format, ...)
{
	t_pf			cache;
	va_list			args;
	int				ret;

	ft_bzero(&cache, sizeof(cache));
	va_start(args, format);
	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format += cache_init(&cache, format, args);
			ret += (cache.valid ? handler(&cache, args) : 0);
			if (!cache.valid || ret == -1)
				return (ret);
			ft_bzero(&cache, sizeof(cache));
		}
		else
		{
			format += write(1, &*format, 1);
			ret++;
		}
	}
	va_end(args);
	return (ret);
}

int					cache_init(t_pf *cache, const char *f, va_list args)
{
	int				t;
	int				read;

	read = 1;
	f++;
	t = cache_flags(cache, f);
	f += t;
	read += t;
	t = cache_width(cache, f, args);
	f += t;
	read += t;
	t = cache_precision(cache, f, args);
	f += t;
	read += t;
	t = cache_length(cache, f);
	f += t;
	read += t;
	t = cache_specifier(cache, f, "cspdiouxXfb%\0");
	f += t;
	read += t;
	return (read);
}

int					handler(t_pf *cache, va_list arg)
{
	int				(*handle[12])(t_pf *, va_list);
	int				func;
	int				write;

	handle[0] = c_handler;
	handle[1] = s_handler;
	handle[2] = p_handler;
	handle[3] = d_handler;
	handle[4] = d_handler;
	handle[5] = o_handler;
	handle[6] = u_handler;
	handle[7] = x_handler;
	handle[8] = x_handler;
	handle[9] = f_handler;
	handle[10] = b_handler;
	handle[11] = mod_handler;
	func = ft_strchrn("cspdiouxXfb%", cache->specifier);
	write = handle[func](cache, arg);
	return (write);
}
