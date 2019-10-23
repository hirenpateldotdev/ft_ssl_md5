/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:06:03 by hirenpat          #+#    #+#             */
/*   Updated: 2019/05/22 17:06:05 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		cache_flags(t_pf *cache, const char *f)
{
	int ret;

	ret = 0;
	while (*f && ft_strchr("-+ #0", *f) != NULL)
	{
		cache->minus = ((*f == MINUS) ? 1 : cache->minus);
		cache->plus = ((*f == PLUS) ? 1 : cache->plus);
		cache->space = ((*f == SPACE) ? 1 : cache->space);
		cache->hashtag = ((*f == HASHTAG) ? 1 : cache->hashtag);
		cache->zero = ((*f == ZERO) ? 1 : cache->zero);
		f++;
	}
	ret += cache->minus ? 1 : 0;
	ret += cache->plus ? 1 : 0;
	ret += cache->space ? 1 : 0;
	ret += cache->hashtag ? 1 : 0;
	ret += cache->zero ? 1 : 0;
	return (ret);
}

int		cache_width(t_pf *cache, const char *f, va_list args)
{
	int		asterisk_f;
	int		ret;

	ret = 0;
	asterisk_f = 0;
	if (*f == '*')
	{
		ret += asterisk_int(&cache->width, args);
		asterisk_f = 1;
		f++;
	}
	while (IS_NUM(*f) && !asterisk_f)
	{
		cache->width = (cache->width * 10) + (*f++ - '0');
		ret++;
	}
	return (ret);
}

int		cache_precision(t_pf *cache, const char *f, va_list args)
{
	int		asterisk_f;
	int		ret;

	ret = 0;
	asterisk_f = 0;
	cache->precision = -1;
	if (*f != '.')
		return (ret);
	cache->precision = 0;
	f++;
	ret++;
	if (*f == '*')
	{
		ret += asterisk_int(&cache->precision, args);
		asterisk_f = 1;
		f++;
	}
	while (IS_NUM(*f) && !asterisk_f)
	{
		cache->precision = (cache->precision * 10) + (*f++ - '0');
		ret++;
	}
	return (ret);
}

int		cache_length(t_pf *cache, const char *f)
{
	int ret;

	ret = 0;
	if (*f == 'h' || *f == 'l')
		cache->length = (*f == 'h' ? H : L);
	else if (*f == 'j' || *f == 'z')
		cache->length = (*f == 'j' ? J : Z);
	else if (*f == 'L' || *f == 'U')
		cache->length = (*f == 'L' ? UL : L);
	if (cache->length)
		ret += (f++ ? 1 : 1);
	if ((cache->length == H && *f == 'h') || (cache->length == L && *f == 'l'))
		cache->length = (*f == 'h' ? HH : LL);
	if (cache->length == HH || cache->length == LL)
		ret += (f++ ? 1 : 1);
	return (ret);
}

int		cache_specifier(t_pf *cache, const char *f, char *specifier)
{
	int ret;

	ret = 1;
	while (*f && *specifier)
	{
		if (*specifier == *f)
		{
			cache->specifier = *specifier;
			cache->valid = 1;
			return (ret);
		}
		specifier++;
	}
	if (!cache->specifier)
	{
		while (!is_spe(*f) && !ft_strchr(specifier, *f))
			f += ret++ ? 1 : 1;
		if (is_spe(*f))
		{
			cache->specifier = *f;
			cache->valid = 1;
		}
	}
	return (ret);
}
