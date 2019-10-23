/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"

void			init_structs(t_ssl *ssl, t_input **input)
{
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
}
