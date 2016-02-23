/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:27:21 by atoupart          #+#    #+#             */
/*   Updated: 2016/02/23 19:26:31 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int const fd, char **line)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	int		x;
	int		i;

	i = -1;
	while (fd)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		x = -1;
		ptc('"');ptc(buf[ret - 2]);ptc('"');ptcn;
		while (++x < ret)
		{
			if (buf[x] == '\n')
				return (1);
			if (buf[x] == 032)
				return (0);
			(*line)[++i] = buf[x];
		}
	}
	return (0);
}
