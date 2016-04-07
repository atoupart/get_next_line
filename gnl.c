/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:27:21 by atoupart          #+#    #+#             */
/*   Updated: 2016/02/26 16:49:31 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int const fd, char **line)
{
	int				ret;
	char			*buf;
	static char		*str;
	char			*tmp;

	if (line == NULL || fd < 0)
		return (-1);
	if (str && (tmp = ft_strchr(str, '\n')))
	{
		*line = ft_strsub(str, 0, tmp - str);
		str = ft_strsub(str, tmp + 1 - str, (str + ft_strlen(str)) - tmp);
		return (1);
	}
	buf = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!str)
			str = ft_strnew(0);
		if (ret == -1)
			return (-1);
		str = ft_strjoin(str, buf);
		if ((tmp = ft_strchr(str, '\n')))
		{
			*line = ft_strsub(str, 0, tmp - str);
			str = ft_strsub(str, tmp + 1 - str, (str + ft_strlen(str)) - tmp);
			return (1);
		}
		else if (ret != BUFF_SIZE)
		{
			*line = str;
			ft_strdel(&str);
			return (1);
		}
	}
	if (str && ret == 0)
	{
		*line = str;
		ft_strdel(&str);
		return (1);
	}
	return (0);
}
