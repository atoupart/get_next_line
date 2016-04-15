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
	static char		*str[12];
	char			*tmp;

	if (line == NULL || fd < 0)
		return (-1);
	if (str[fd] && (tmp = ft_strchr(str[fd], '\n')))
	{

		*line = ft_strsub(str[fd], 0, tmp - str[fd]);

		str[fd] = ft_strsub(str[fd], tmp + 1 - str[fd], (str[fd] + ft_strlen(str[fd])) - tmp);
		return (1);
	}


	buf = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!str[fd])
			str[fd] = ft_strnew(0);
		
		str[fd] = ft_strjoin(str[fd], buf);

		bzero(buf, BUFF_SIZE);

		if ((tmp = ft_strchr(str[fd], '\n')))
		{
			*line = ft_strsub(str[fd], 0, tmp - str[fd]);

			buf = ft_strsub(str[fd], tmp + 1 - str[fd], (str[fd] + ft_strlen(str[fd])) - tmp);
			if (*buf != '\0')
			{
				str[fd] = buf;
			}
			else
				ft_strdel(&str[fd]);
			return (1);
		}
		else if (ret != BUFF_SIZE)
		{
			*line = str[fd];

			ft_strdel(&str[fd]);
			return (1);
		}
	}


	if (str[fd] && ret == 0 && *str[fd] != '\n' && *str[fd] != '\0')
	{
		*line = str[fd];

		ft_strdel(&str[fd]);
		return (1);
	}
	if (ret == -1)
			return (-1);
	return (0);
}
