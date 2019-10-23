/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:32:07 by hirenpat          #+#    #+#             */
/*   Updated: 2018/12/17 15:32:09 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long		ft_read_fd(int fd, char **str)
{
	long long			ret;
	unsigned long long	len;
	char				buffer[BUFF_SIZE + 1];

	len = 0;
	*str = malloc(sizeof(char) * 1);
	*str[0] = '\0';
	while ((ret = ft_read(fd, buffer, BUFF_SIZE)) > 0)
	{
		ft_strappend(str, buffer);
		len += ret;
	}
	return (len);
}
