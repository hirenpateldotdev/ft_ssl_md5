/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"

int				dispatch(t_ssl *ssl, t_input **input)
{
	int			ret;
	int			(*handle[5])(t_ssl *, t_input **);

	handle[0] = md5_handler;
	handle[1] = sha224_handler;
	handle[2] = sha256_handler;
	handle[3] = sha384_handler;
	handle[4] = sha512_handler;
	ret = handle[ssl->command](ssl, input);
	return (ret);
}

int				main(int ac, char **av)
{
	t_ssl		*ssl;
	t_input		**input;
	int			i;

	i = -1;
	ssl = malloc(sizeof(t_ssl));
	ft_bzero(ssl, sizeof(t_ssl));
	input = malloc(sizeof(t_input *) * INPUT_MAX);
	while (++i < INPUT_MAX)
	{
		input[i] = malloc(sizeof(t_input));
		ft_bzero(input[i], sizeof(t_input));
	}
	ssl->ac = ac;
	init_structs(ssl, input);
	if (parse_arguments(ssl, input, ac, av) == 1)
		dispatch(ssl, input);
	free_structs(ssl, input);
	return (1);
}
