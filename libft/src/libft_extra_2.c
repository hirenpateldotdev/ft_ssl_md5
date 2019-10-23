/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_extra_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:22:03 by hirenpat          #+#    #+#             */
/*   Updated: 2019/05/22 17:22:07 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char				*ft_strjoinf(char *str_1, char *str_2)
{
	char			*result;

	result = ft_strjoin(str_1, str_2);
	free(str_1);
	return (result);
}

long double			ft_round(long double d, int p)
{
	long double		rounded;
	long double		m;

	m = 1;
	while (p--)
		m *= 10;
	rounded = ((int)(d * m + .5) / m);
	return (rounded);
}

int					asterisk_int(int *nb, va_list args)
{
	int				temp;

	if (nb == NULL)
		temp = va_arg(args, int);
	else
		*nb = va_arg(args, int);
	return (1);
}

int					is_spe(char x)
{
	return (x == 'c' || x == 's' || x == 'p' || x == 'd' || x == 'i' ||
	x == 'o' || x == 'u' || x == 'x' || x == 'X' || x == 'f' || x == '%'
	|| x == 'd');
}

char				*ft_strset(char **dest, char *src)
{
	ft_strdel(dest);
	return (ft_strdup(src));
}
