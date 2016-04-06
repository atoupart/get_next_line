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
// gerer les cas d'erreurs //
	if (line == NULL || fd < 0)
		return (-1);


	pte("1");
	if (str && (tmp = ft_strchr(str, '\n')))
	{
			pts("2 str des l'entrer de gnl  avec \n = ");pte(str);
			*line = ft_strsub(str, 0, tmp - str);
			pts("3 line = ");pte(*line);
			str = ft_strsub(str, tmp + 1 - str, (str + ft_strlen(str)) - tmp);
			pts("4 str = ");pte(str);
			return (1);
	}


// BOUCLE READ //

		buf = ft_strnew(BUFF_SIZE);
		if (!str)
			str = ft_strnew(0);
		while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
		{
		

			
			buf[ret] = '\0';
			str = ft_strjoin(str, buf);
			pts("5 str = ");pte(str);
			if ((tmp = ft_strchr(str, '\n')))
			{	
				pte("6");
				*line = ft_strsub(str, 0, tmp - str);
				pts("7 line = ");pte(*line);
				str = ft_strsub(str, tmp + 1 - str, (str + ft_strlen(str)) - tmp);
				pts("8 str = ");pte(str);
				return (1);
			}
			else if (ret != BUFF_SIZE)//sert uniquement pour la derniere ligne
			{
				*line = str;
				pts("9 line = ");pte(*line);
				return (1);
			}
		}
	if (ret == -1)
		return (-1);
	return (0);
}
