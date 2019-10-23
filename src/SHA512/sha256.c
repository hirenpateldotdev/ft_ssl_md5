/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha256.h"

static void				init_words(uint8_t *block, uint32_t *sub_block)
{
	uint32_t			*var;

	var = malloc(sizeof(uint32_t) * 7);
	ft_bzero(var, sizeof(uint32_t) * 7);
	ft_memcpy(sub_block, block, sizeof(int) * 16);
	V_I = 0;
	while (V_I < 16)
		reverse_bytes(sub_block + V_I++, sizeof(int));
	V_I = 16;
	while (V_I < 64)
	{
		V_S1 = RIGHTROTATE(sub_block[V_I - 15], 7) ^
		RIGHTROTATE(sub_block[V_I - 15], 18) ^ (sub_block[V_I - 15] >> 3);
		V_S2 = RIGHTROTATE(sub_block[V_I - 2], 17) ^
		RIGHTROTATE(sub_block[V_I - 2], 19) ^ (sub_block[V_I - 2] >> 10);
		sub_block[V_I] = sub_block[V_I - 16] + V_S1 + sub_block[V_I - 7] + V_S2;
		V_I++;
	}
	free(var);
}

void					sha256_get_hash(uint32_t *hash, uint32_t *sub_block,
										uint32_t i)
{
	uint32_t			*var;

	var = malloc(sizeof(uint32_t) * 7);
	ft_bzero(var, sizeof(uint32_t) * 7);
	V_I = i;
	V_S2 = RIGHTROTATE(H_E, 6) ^ RIGHTROTATE(H_E, 11) ^ RIGHTROTATE(H_E, 25);
	V_C = (H_E & H_F) ^ ((~H_E) & H_G);
	V_T1 = H_H + V_S2 + V_C + g_ssl_k[V_I] + sub_block[V_I];
	V_S1 = RIGHTROTATE(H_A, 2) ^ RIGHTROTATE(H_A, 13) ^ RIGHTROTATE(H_A, 22);
	V_M = (H_A & H_B) ^ (H_A & H_C) ^ (H_B & H_C);
	V_T2 = V_S1 + V_M;
	H_H = H_G;
	H_G = H_F;
	H_F = H_E;
	H_E = H_D + V_T1;
	H_D = H_C;
	H_C = H_B;
	H_B = H_A;
	H_A = V_T1 + V_T2;
	free(var);
}

uint32_t				*sha256_get_chuck_hash(uint8_t *block, uint32_t *hash)
{
	static uint32_t		block_hash[8];
	uint32_t			sub_block[64];
	uint32_t			*var;

	init_words(block, sub_block);
	ft_memcpy(block_hash, hash, sizeof(uint32_t) * 8);
	var = malloc(sizeof(uint64_t) * 7);
	V_I = 0;
	while (V_I < 64)
	{
		sha256_get_hash(block_hash, sub_block, V_I);
		V_I++;
	}
	free(var);
	return (block_hash);
}

char					*sha256(uint8_t **blocks, int number_blocks)
{
	uint32_t			*block_hash;
	uint32_t			*hash;
	int					i;
	char				*d;
	int					x;

	i = -1;
	hash = malloc(sizeof(uint32_t) * 8);
	x = -1;
	while (++x < 8)
		hash[x] += g_ssl_var[x];
	while (++i < number_blocks)
	{
		block_hash = sha256_get_chuck_hash(blocks[i], hash);
		x = -1;
		while (++x < 8)
			hash[x] += block_hash[x];
	}
	i = 0;
	while (i < 8)
		reverse_bytes(hash + i++, sizeof(int));
	d = sha256_hash((uint8_t*)hash);
	free(hash);
	return (d);
}
