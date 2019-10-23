/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

uint32_t				*md5_get_hash(uint32_t *hash, uint32_t *var)
{
	if (V_I <= 15)
	{
		V_F = (H_B & H_C) | ((~H_B) & H_D);
		V_G = V_I;
	}
	else if (V_I <= 31)
	{
		V_F = (H_D & H_B) | ((~H_D) & H_C);
		V_G = (5 * V_I + 1) % 16;
	}
	else if (V_I <= 47)
	{
		V_F = H_B ^ H_C ^ H_D;
		V_G = (3 * V_I + 5) % 16;
	}
	else
	{
		V_F = H_C ^ (H_B | (~H_D));
		V_G = (7 * V_I) % 16;
	}
	return (var);
}

uint32_t				*md5_get_chuck_hash(uint8_t *block, uint32_t hash[4])
{
	static uint32_t		block_hash[4];
	uint32_t			sub_block[16];
	uint32_t			*var;

	ft_memcpy(sub_block, block, sizeof(int) * 16);
	ft_memcpy(block_hash, hash, sizeof(int) * 4);
	var = malloc(sizeof(uint64_t) * 4);
	V_I = 0;
	while (V_I < 64)
	{
		var = md5_get_hash(hash, var);
		V_F = V_F + H_A + g_sin[V_I] + sub_block[V_G];
		H_A = H_D;
		H_D = H_C;
		H_C = H_B;
		H_B = H_B + LEFTROTATE(V_F, g_shift[V_I]);
		V_I++;
	}
	return (block_hash);
}

char					*md5(uint8_t **blocks, int number_blocks)
{
	uint32_t			*block_hash;
	static uint32_t		hash[4];
	int					i;

	i = -1;
	hash[0] = g_var[0];
	hash[1] = g_var[1];
	hash[2] = g_var[2];
	hash[3] = g_var[3];
	while (++i < number_blocks)
	{
		block_hash = md5_get_chuck_hash(blocks[i], hash);
		hash[0] += block_hash[0];
		hash[1] += block_hash[1];
		hash[2] += block_hash[2];
		hash[3] += block_hash[3];
	}
	return (md5_hash((unsigned char*)hash));
}
