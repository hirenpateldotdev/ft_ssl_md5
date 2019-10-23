/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# define INPUT input[ssl->current_input]
# define I_INPUT ssl->current_input
# define INPUT_MAX 100
# define STDIN 0
# define FILE 1
# define STRING 2
# define VALID 1
# define INVALID -1
# define FLAG_P ssl->p
# define FLAG_Q ssl->Q
# define FLAG_R ssl->R
# define FLAG_S ssl->s
# define NOT_FOUND 0
# define FOUND 1
# define ARG_NOT_FOUND -1
# define SET_NO_ARG ssl->error[0] = 1
# define SET_INVALID_COMMAND ssl->error[1] = 1
# define SET_INVALID_STRING ssl->error[2] = 1
# define SET_INVALID_FLAG ssl->error[3] = 1

typedef struct			s_ssl {

	int					command;
	char				*command_str;
	int					ac;
	int					p;
	int					q;
	int					r;
	int					s;
	int					current_input;
	int					error[5];
	int					valid;
}						t_ssl;

typedef struct			s_block
{
	int					command;
	uint8_t				*padded_content;
	uint64_t			padded_content_length;
	uint64_t			content_length;
	uint8_t				**blocks;
	int					number_blocks;
}						t_block;

typedef struct			s_input
{
	int					type;
	uint64_t			length;
	char				*descriptor;
	char				*content;
	char				*digest;
	t_block				*b_p;
}						t_input;

#endif
