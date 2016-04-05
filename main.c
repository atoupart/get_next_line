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

int			main(int argc, char **argv)
{
	int		i = 0;
	char	*line;
	int		fd;
	int		recup = 1;

	fd = open(argv[1], O_RDONLY);
	while (i != 3 && recup != 0)
	{
		recup = get_next_line(fd, &line);
		i++;
		pts("line ");ptn(i);pts(" =");ptcn;pts("''");pts(line);pte("''");;
		
	}
	close(fd);
	return (0);
}

