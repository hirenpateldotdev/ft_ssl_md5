/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"

void		free_block(t_block *b)
{
	int		i;

	i = -1;
	free(b->padded_content);
	while (++i < b->number_blocks)
		free(b->blocks[i]);
	free(b->blocks);
	free(b);
}

void		free_input(t_ssl *ssl, t_input **input)
{
	int		i;

	i = -1;
	while (++i < ssl->current_input)
	{
		free(input[i]->content);
		free(input[i]->descriptor);
		free(input[i]->digest);
		if (ssl->valid)
			free_block(input[i]->b_p);
	}
	i = -1;
	while (++i < INPUT_MAX)
		free(input[i]);
	free(input);
}

void		free_structs(t_ssl *ssl, t_input **input)
{
	free_input(ssl, input);
	free(ssl);
}
