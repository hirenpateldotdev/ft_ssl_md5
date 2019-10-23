/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			reverse_bytes(void *bytes, uint32_t n)
{
	uint32_t	i;
	uint8_t		tmp;

	i = 0;
	n--;
	while (i < n)
	{
		tmp = ((uint8_t*)bytes)[i];
		((uint8_t*)bytes)[i] = ((uint8_t*)bytes)[n];
		((uint8_t*)bytes)[n] = tmp;
		i++;
		n--;
	}
}