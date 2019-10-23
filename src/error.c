/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ssl.h"

int			usage(int x)
{
	(void)x;
	ft_printf("usage: ft_ssl command [command opts] [command args]\n");
	return (-1);
}

int			invalid_flag(char invalid_flag)
{
	ft_printf("md5: illegal option -- %c\n", invalid_flag);
	return (-1);
}

int			invalid_command(char *invalid_command)
{
	int		i;

	i = -1;
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n",
				invalid_command);
	ft_printf("Standard commands:\n\n");
	ft_printf("Message Digest commands:\n");
	while (++i < g_valid_commands)
		ft_printf("%s\n", g_command[i]);
	ft_printf("\nCipher commands:\n");
	return (-1);
}

int			invalid_string(void)
{
	ft_printf("md5: option requires an argument --s\n");
	return (-1);
}

int			invalid_file(char *invalid_file, char *command_val)
{
	ft_printf("ft_ssl: %s: %s: No such file or directory or can't access\n",
				command_val, invalid_file);
	return (-1);
}
