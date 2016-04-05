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


// verifier les \n  dans la static str avant de read //
	// if (str && ft_strchr(str, '\n'))
	// {
	// 	pte("pass");
	// 	if (resolve_line(&str, line))
	// 		return (1);
	// }
	if (str)
	{
		if ((tmp = ft_strchr(str, '\n')))
		{
			*line = ft_strsub(str, 0, tmp - str);
			str = ft_strsub(str, tmp - str, (str + ft_strlen(str)) - tmp);
			return (1);
		}
		else
			str = ft_strsub(str, tmp - str, (str + ft_strlen(str)) - tmp);
	}


// BOUCLE READ //
	// else
	// {
		buf = ft_strnew(BUFF_SIZE);
		if (!str)
			str = ft_strnew(0);
		while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
		{
			if (ret == -1)
				return (-1);
			// buf[ret] = '\0';
			if (str && (tmp = ft_strchr(buf, '\n')))
			{
				str = ft_strjoin(str, buf);
				*line = ft_strsub(str, 0, tmp - str);
				str = ft_strsub(buf, tmp - buf, (buf + ret) - tmp);
				return (1);
			}
			else if ((tmp = ft_strchr(buf, '\n')))
			{	
				*line = ft_strsub(buf, 0, tmp - buf);
				str = ft_strsub(buf, tmp - buf, (buf + ret) - tmp);
				return (1);
			}
			else  //sert uniquement pour la derniere ligne
				{
					*line = ft_strjoin(str, buf);
					return (0);
				}
			
		}
		// pte(str);
	// 	if (resolve_line(&str, line))
	// 		return (1);
	// 	else
	// 	{
	// 		*line = str;
	// 		return (line ? 1 : 0);
	// 	}
	// }
	return (0);
}
