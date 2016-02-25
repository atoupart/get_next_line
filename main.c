/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:39:54 by atoupart          #+#    #+#             */
/*   Updated: 2016/02/25 17:23:36 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int			main(int argc, char **argv)
{
	int		i;
	int 	x;
	char	*line;
	int		fd;
	int		ret;

	//if (!(line = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE + 1)))
	if (!(line = (char *)ft_strnew(BUFF_SIZE + 1)))
	{
		pts("malloc * line error");
		exit(EXIT_FAILURE);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		pts("open error");
		exit(EXIT_FAILURE);
	}
	// i = -1;
	// x = 0;
	// while (x++ <= 0)
	// {
	// 	i = get_next_line(fd, &line);
	// 	if (i != 0)
	// 	{
	// 		pts(&*line);
	// 		ptcn;
	// 	}
	// }
	while ((ret = get_next_line(fd, &line)))
		printf("ret = %d\n, line = %s\n\n", ret, line);
	if (close(fd) == -1)
	{
		pts("close error");
		exit(EXIT_FAILURE);
	}
	return (0);
}

