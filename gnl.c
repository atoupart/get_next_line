/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_ligne.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 11:42:18 by atoupart          #+#    #+#             */
/*   Updated: 2016/04/05 11:42:22 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int const fd, char **line)
{
	int				ret;
	char			*buf;
	static char		*str;
	char			*tmp;
// gerer les cas d'erreurs //
	if (line == NULL || fd < 0)
		return (-1);

	if (str && (tmp = ft_strchr(str, '\n')))
	{
			*line = ft_strsub(str, 0, tmp - str);
			str = ft_strsub(str, tmp + 1 - str, (str + ft_strlen(str)) - tmp);
			return (1);
	}


// BOUCLE READ //

		buf = ft_strnew(BUFF_SIZE);
		if (!str)
			str = ft_strnew(0);
		while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
		

			
			buf[ret] = '\0';
			str = ft_strjoin(str, buf);
			if ((tmp = ft_strchr(str, '\n')))
			{	
				*line = ft_strsub(str, 0, tmp - str);
				str = ft_strsub(str, tmp + 1 - str, (str + ft_strlen(str)) - tmp);
				return (1);
			}
			else if (ret != BUFF_SIZE)//sert uniquement pour la derniere ligne
			{
				*line = str;
				return (1);
			}
		}
	if (ret == -1)
		return (-1);
	return (0);
}
