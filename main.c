/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:39:54 by atoupart          #+#    #+#             */
/*   Updated: 2016/02/09 18:10:42 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			main(int argc, char **argv)
{
	int		i;
	char	**line;
	int		fd;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		pts("open error");
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < 10)
	{
		get_next_line(fd, line);
	}

	if (close(fd) == -1)
	{
		pts("close error");
		exit(EXIT_FAILURE);
	}
	return (0);
}

