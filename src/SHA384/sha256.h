/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA256_H
# define FT_SHA256_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../../inc/struct.h"
# include "../../libft/inc/ft_printf.h"
# define H_A hash[0]
# define H_B hash[1]
# define H_C hash[2]
# define H_D hash[3]
# define H_E hash[4]
# define H_F hash[5]
# define H_G hash[6]
# define H_H hash[7]
# define V_S1 var[0]
# define V_S2 var[1]
# define V_T1 var[2]
# define V_T2 var[3]
# define V_M var[4]
# define V_C var[5]
# define V_I var[6]
# define DIGEST_LENGTH 32
# define PADDED_LENGTH 9
# define BLOCK_LENGTH 64
# define S_B input->b_p
# define S_I input
# define P_C_L (S_B->number_blocks * BLOCK_LENGTH)
# define LEFTROTATE(X, N) ((X << N) | (X >> (32 - N)))
# define RIGHTROTATE(X, N) ((X >> N) | (X << (32 - N)))

static const uint32_t			g_ssl_k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
	0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
	0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
	0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
	0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
	0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

static const uint32_t			g_ssl_var[8] = {
	0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
	0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

char					*sha256(uint8_t **blocks_arr, int arr_len);
char					*sha256_hash(uint8_t *hash);
void					reverse_bytes(void *bytes, uint32_t n);
#endif
