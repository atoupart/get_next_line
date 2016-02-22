/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:27:21 by atoupart          #+#    #+#             */
/*   Updated: 2016/02/22 20:28:35 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
comme le buff size peu etre different, il faut faire en sorte qu'il y ait
une boucle read et que le buf s'arrete qudn il rencontre un \n ou u EOF

et je ne sait pas encore comment reussir une boucle qui appelerait gnl
**line .. comment saurait til quel ligne il doit lire si c'est lui qui a read..

et puis faire un makefile, peut etre pratique ca =p
courage.
*/

int			get_next_line(int const fd, char **line)
{
	int		ret;
//	char	buf[BUFF_SIZE + 1];

	if ((ret = read(fd, *line, BUFF_SIZE)) == -1)
	{
		pts("read error");exit(EXIT_FAILURE);
	}
	pts("read reussi");ptcn;
	ptn(ret);ptcn;
	ft_putstr(*line);
	// ft_putchar(*line[0]);ptcn;
	int i = -1;
	while (++i < 20) {
		ft_putchar((*line)[i]);
	}
	//ft_putchar(*line[200]);ptcn;
	(*line)[ret] = '\0';
	ptcn;
	return (0);
/*
	i = -1;
	if ((ret = read(fd, buf, BUF_SIZE)) == BUF_SIZE)
		return (-1);
	buf[ret] = '\0';
	while (++i < ret && buf[i] != '\n' && buf[i] != 003)
		line[i] = &buf[i];
	if (buf[ret - 1] == 003)
		return (0);
	return(1);
*/
}
