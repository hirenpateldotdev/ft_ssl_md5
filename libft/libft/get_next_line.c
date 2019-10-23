/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:32:07 by hirenpat          #+#    #+#             */
/*   Updated: 2018/12/17 15:32:09 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_read(int fd, char *buffer, int buff_size)
{
	int			return_value;

	return_value = read(fd, buffer, buff_size);
	buffer[return_value] = '\0';
	return (return_value);
}

void			ft_strtrim_todest(char **dest, char **src, int start, int end)
{
	char		*temp;

	*dest = ft_strsub(*src, start, end);
	temp = ft_strdup(*src + end + 1);
	free(*src);
	*src = temp;
	if (*src[0] == '\0')
		ft_strdel(src);
}

void			ft_strappend(char **str, char *sub)
{
	char		*temp;

	temp = ft_strjoin(*str, sub);
	free(*str);
	*str = temp;
}

int				get_next_line(const int fd, char **line)
{
	static char	*hm[MAX_FD];
	char		b[BUFF_SIZE + 1];
	int			i;
	int			end;

	if (INVALID_FD(fd) == 1 || line == NULL || read(fd, b, 0) < 0)
		return (-1);
	if (hm[fd] == NULL)
		hm[fd] = ft_strnew(1);
	while (ft_strchr(hm[fd], '\n') == 0 && (i = ft_read(fd, b, BUFF_SIZE)) > 0)
		ft_strappend(&hm[fd], b);
	if (i == 0 && (hm[fd] == NULL || hm[fd][0] == '\0'))
		return (0);
	end = ft_strchrn(hm[fd], '\n');
	if (hm[fd][end] == '\n')
		ft_strtrim_todest(&*line, &hm[fd], 0, end);
	else
	{
		if (BUFF_SIZE == i)
			return (get_next_line(fd, line));
		*line = ft_strdup(hm[fd]);
		ft_strdel(&hm[fd]);
	}
	return (1);
}
