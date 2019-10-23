/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha224.h"\

char			*sha224_hash(uint8_t *hash)
{
	int			i;
	char		*digest;
	char		*alpha_num;

	alpha_num = "0123456789abcdef";
	digest = ft_memalloc(sizeof(char) * 65);
	i = 0;
	while (i < 64)
	{
		digest[i] = alpha_num[*hash / 16];
		digest[i + 1] = alpha_num[*hash % 16];
		hash++;
		i += 2;
	}
	return (digest);
}

void			reverse_bytes_224(void *bytes, uint32_t n)
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

int				init_sha224_block(t_input *input)
{
	int			i;

	i = -1;
	S_B = malloc(sizeof(t_block));
	S_B->content_length = S_I->length;
	S_B->padded_content_length = S_I->length + PADDED_LENGTH;
	S_B->number_blocks = ((S_B->padded_content_length / BLOCK_LENGTH) +
			((S_B->padded_content_length % BLOCK_LENGTH) == 0 ? 0 : 1));
	S_B->padded_content = malloc(sizeof(uint8_t) *
					(S_B->number_blocks * BLOCK_LENGTH));
	ft_bzero(S_B->padded_content, (S_B->number_blocks * BLOCK_LENGTH));
	ft_memcpy(S_B->padded_content, S_I->content, S_I->length);
	S_B->padded_content[S_I->length] |= (uint8_t)0x80;
	*((uint64_t *)(S_B->padded_content + P_C_L - 8)) = S_B->content_length * 8;
	reverse_bytes_224(S_B->padded_content + (P_C_L - 8), 8);
	S_B->blocks = malloc(sizeof(uint8_t *) * S_B->number_blocks);
	while (++i < S_B->number_blocks)
	{
		S_B->blocks[i] = malloc(sizeof(uint8_t) * BLOCK_LENGTH);
		ft_bzero(S_B->blocks[i], BLOCK_LENGTH);
		ft_memcpy(S_B->blocks[i], &S_B->padded_content
					[i * BLOCK_LENGTH], BLOCK_LENGTH);
	}
	return (1);
}

int				sha224_format_digest(t_ssl *ssl, t_input *input)
{
	if (ssl->q == 1 || ssl->ac == 2)
		ft_printf("%s\n", input->digest);
	else if (ssl->q == 1 && input->type == STDIN)
		ft_printf("%s%s\n", input->descriptor, input->digest);
	else if (ssl->r == 1)
	{
		if (input->type == FILE)
			ft_printf("%s %s\n", input->digest, input->descriptor);
		if (input->type == STRING)
			ft_printf("%s \"%s\"\n", input->digest, input->descriptor);
		if (input->type == STDIN)
			ft_printf("%s%s\n", input->descriptor, input->digest);
	}
	else if (!ssl->r && !ssl->q)
	{
		if (input->type == FILE)
			ft_printf("SHA224 (%s) = %s\n", input->descriptor, input->digest);
		if (input->type == STRING)
			ft_printf("SHA224 (\"%s\") = %s\n",
						input->descriptor, input->digest);
		if (input->type == STDIN)
			ft_printf("%s%s\n", input->descriptor, input->digest);
	}
	return (1);
}

int				sha224_handler(t_ssl *ssl, t_input **input)
{
	int			i;

	i = -1;
	while (++i < ssl->current_input)
		init_sha224_block(input[i]);
	i = -1;
	while (++i < ssl->current_input)
		input[i]->digest = sha224(input[i]->b_p->blocks,
									input[i]->b_p->number_blocks);
	i = -1;
	while (++i < ssl->current_input)
		sha224_format_digest(ssl, input[i]);
	return (1);
}
