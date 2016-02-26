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
	char			*tmp;
	static char		*str;
	int				i;
// gerer les cas d'erreurs //
	if (line == NULL || !fd)
		return (-1);

// verifier les \n  dans la static str avant de read //
	i = 0;
	if ((tmp = ft_strchr(str, '\n')))
	{
		while (str[i] != *tmp)
		{
			(*line)[i] = str[i];
			i++;
		}
		return (1);
	}

// lancement boucle read //
	buf = ft_strnew(BUFF_SIZE);
	str = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) ==  BUFF_SIZE)
	{
		i = 0;
		if ((tmp = ft_strchr(buf, '\n')))
		{
			while (buf[i] != *tmp)
			{
				(*line)[i] = str[i];
				i++;
			}
			return (1);
		}
	}
	return (0);
}

		
/*
	buf = ft_strnew(BUFF_SIZE);
	str = ft_strnew(0); // static = init 0 auto (BSS)
	ret = -1;
	while (ret != 0)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
//		buf[ret] = '\0';
		tmp = (char *)malloc(ft_strlen(str) + ret);
		tmp = ft_strcpy(tmp, str);
//		ft_strdel(&str);
		str = ft_strcat(tmp, buf);
		ft_strdel(&tmp);
		pts(str);ptcn;
	}
	pts(str);ptcn;
	return (0);
}

*/











































