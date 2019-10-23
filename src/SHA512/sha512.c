/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha512.h"

static void				init_words(uint8_t *block, uint64_t *sub_block)
{
	uint64_t			*var;

	var = malloc(sizeof(uint64_t) * 7);
	ft_bzero(var, sizeof(uint64_t) * 7);
	ft_memcpy(sub_block, block, sizeof(int) * 16);
	V_I = 0;
	while (V_I < 16)
		reverse_bytes_512(sub_block + V_I++, sizeof(int));
	V_I = 16;
	while (V_I < 80)
	{
		V_S1 = RR_64(sub_block[V_I - 15], 1) ^ RR_64(sub_block[V_I - 15], 8) \
		^ (sub_block[V_I - 15] >> 7);
		V_S2 = RR_64(sub_block[V_I - 2], 19) ^ RR_64(sub_block[V_I - 2], 61) \
		^ (sub_block[V_I - 2] >> 6);
		sub_block[V_I] = sub_block[V_I - 16] + V_S1 + sub_block[V_I - 7] + \
		V_S2;
		V_I++;
	}
	free(var);
}

void					sha512_get_hash(uint64_t *hash, uint64_t *sub_block,
										uint64_t i)
{
	uint64_t			*var;

	var = malloc(sizeof(uint64_t) * 7);
	ft_bzero(var, sizeof(uint64_t) * 7);
	V_I = i;
	V_S1 = FX(RR_64(H_A, 28), RR_64(H_A, 34), RR_64(H_A, 39));
	V_T1 = FZ(H_A, H_B, H_C, V_S1);
	V_S2 = FX(RR_64(H_E, 14), RR_64(H_E, 18), RR_64(H_E, 41));
	V_T2 = FY(H_E, H_F, H_G, H_H, V_T2, g_ssl_k[i], sub_block[i]);
	H_H = H_G;
	H_G = H_F;
	H_F = H_E;
	H_E = H_D + V_T2;
	H_D = H_C;
	H_C = H_B;
	H_B = H_A;
	H_A = V_T1 + V_T2;
	free(var);
}

uint64_t				*sha512_get_chuck_hash(uint8_t *block, uint64_t *hash)
{
	static uint64_t		block_hash[8];
	uint64_t			sub_block[80];
	uint64_t			*var;

	init_words(block, sub_block);
	ft_memcpy(block_hash, hash, sizeof(uint64_t) * 8);
	var = malloc(sizeof(uint64_t) * 7);
	V_I = 0;
	while (V_I < 80)
	{
		sha512_get_hash(block_hash, sub_block, V_I);
		V_I++;
	}
	free(var);
	return (block_hash);
}

char					*sha512(uint8_t **blocks, int number_blocks)
{
	uint64_t			*block_hash;
	uint64_t			*hash;
	int					i;
	char				*d;
	int					x;

	i = -1;
	hash = malloc(sizeof(uint64_t) * 8);
	x = -1;
	while (++x < 8)
		hash[x] += g_ssl_var[x];
	while (++i < number_blocks)
	{
		block_hash = sha512_get_chuck_hash(blocks[i], hash);
		x = -1;
		while (++x < 8)
			hash[x] += block_hash[x];
	}
	i = 0;
	while (i < 8)
		reverse_bytes_512(hash + i++, sizeof(int));
	d = sha512_hash((uint8_t*)hash);
	free(hash);
	return (d);
}
