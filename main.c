/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:39:54 by atoupart          #+#    #+#             */
/*   Updated: 2016/02/22 20:32:32 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			main(int argc, char **argv)
{
	int		i;
	char	*line;
	int		fd;

	if (!(line = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE + 1)))
	{
		pts("malloc * line error");exit(EXIT_FAILURE);
	}

	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		pts("open error");exit(EXIT_FAILURE);
	}
	get_next_line(fd, &line);
	pts("get next line passe");ptcn;
	// pts(*line);
	if (close(fd) == -1)
	{
		pts("close error");exit(EXIT_FAILURE);
	}
	return (0);
}

