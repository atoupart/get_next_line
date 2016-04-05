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

int		resolve_line(char **str, char **line)
{
	char *tmp;

	if ((tmp = ft_strchr(*str, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(*str);
		return (1);
	}
	else
		return (0);
	

}
