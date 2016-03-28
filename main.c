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
	int		i = 0;
	char	*line;
	int		fd;
	int		recup;

	line = ft_strnew(BUFF_SIZE + 1);

	fd = open(argv[1], O_RDONLY);
	
	while ((recup = get_next_line(fd, &line)))
	{
		i++;
		printf("line %d =\n''%s''\n\n", i, line);
	}

	close(fd);
	return (0);
}

