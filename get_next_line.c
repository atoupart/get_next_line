/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:27:21 by atoupart          #+#    #+#             */
/*   Updated: 2016/02/08 18:23:47 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int const fd, char **line)
{
	int		ret;
	char	buf[BUF_SIZE + 1];

	if ((ret = read(fd, buf, BUF_SIZE)) == BUF_SIZE)
		exit(EXIT_FAILURE);
}
