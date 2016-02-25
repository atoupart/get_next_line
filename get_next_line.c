/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:27:21 by atoupart          #+#    #+#             */
/*   Updated: 2016/02/26 00:42:30 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
int			get_next_line(int const fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static char		*str;
	static int		i;

	i = -1;
	while (ret != 0)
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
	pts(buf);
	str = (char*)malloc(sizeof(char) * ft_strlen(buf));
	ptn(ret);ptcn;
	str = ft_strjoin(str, buf);
	while (str[++i] != '\n')
		(*line)[i] = str[i];
	if (str[i] == '\n')
		return (1);
	return (0);
}
*/

static void		search_n(int const fd, char *str) // surement plus de parametre
{


int				get_next_line(int const fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	static char		*str;
	static int		i;

	ft_bzero(buf, BUFF_SIZE + 1);
	str = search_n(fd, str)
	ret = -1;
	i = -1;
	while (ret != 0)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[ret] = '\0'; // apparemment useless
		tmp = (char*)malloc(ft_strlen(str) + ret);
		tmp = ft_memcpy(tmp, str, ft_strlen(str) + 1);
//	:w
//	ft_strdel(&str);
		str = ft_strcat(tmp, buf);
//		ft_strdel(&tmp);
		pts(str);ptcn;
	}
	pts(str);ptcn;
	return (get_next_line(fd, line);
}












































