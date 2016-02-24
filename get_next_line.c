/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:27:21 by atoupart          #+#    #+#             */
/*   Updated: 2016/02/24 18:25:26 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int const fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static char		*str;
	static int		i;

	i = -1;
	while (1)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		ptn(ret);ptcn;
		str = ft_strjoin(str, buf);
		while (str[++i] != '\n')
			(*line)[i] = str[i];
		if (str[i] == '\n')
			return (1);
		return (0);
	}
}
 apres les multiples appel de gnl, static str a tout enregistrer
 et c'est la decoupe de str par les \n  dans line que je dois aprofondir

















































