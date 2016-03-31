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
	// i = 0;
	// if (ft_strchr(str, '\n'))
	// {
	// 	while (str[i] != *tmp)
	// 	{
	// 		(*line)[i] = str[i];
	// 		i++;
	// 	}
	// 	return (1);
	// }


	buf = ft_strnew(BUFF_SIZE);
	str = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE) == BUFF_SIZE))
	{
		str = ft_strjoin(str, buf);   //peutetre ensuite strdel(buf);
		if (ft_strchr(str, '\n'))
			break ;
	}
	if (ret != BUFF_SIZE && BUFF_SIZE != 1)
		str = ft_strjoin(str, buf);
	i = -1;
	*line = ft_strnew(ft_strlen(str));
	if (ret == BUFF_SIZE)            // --------------sert uniquement a eviter de renvoyer '\n'
		while(str[++i] != '\n')
			(*line)[i] = str[i];
	else
		*line = str;
	if (*str == '\0')
		return (0);
	return (1);
}
