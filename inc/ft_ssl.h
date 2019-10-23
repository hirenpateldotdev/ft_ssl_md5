/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "struct.h"
# include "../libft/inc/ft_printf.h"
# include "../src/MD5/md5.h"

static const int	g_valid_commands = 2;

static const char	*g_command[2] = {
	"md5", "sha256"
};

void				free_structs(t_ssl *ssl, t_input **input);
void				init_structs(t_ssl *ssl, t_input **input);
int					parse_arguments(t_ssl *ssl, t_input **input, int arg_len,
									char **arg);
int					usage(int x);
int					invalid_flag(char invalid_flag);
int					invalid_command(char *invalid_command);
int					invalid_string(void);
int					invalid_file(char *invalid_file, char *command_val);
int					md5_handler(t_ssl	*ssl, t_input **input);
int					sha256_handler(t_ssl	*ssl, t_input **input);
int					sha224_handler(t_ssl	*ssl, t_input **input);
int					sha512_handler(t_ssl	*ssl, t_input **input);
int					sha384_handler(t_ssl	*ssl, t_input **input);
#endif
