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
	int		fd2;
	int		gnl = 1;
	int		gnl2 = 0;

	fd = open(argv[1], O_RDONLY);
	// fd2 = open(argv[2], O_RDONLY);
	
	while (gnl > 0 || gnl2 > 0)
	{
		i++;
		if ((gnl = get_next_line(fd, &line)))
		{
			pte("================================================================================");
			pts("fd = ");ptn(fd);pts(" gnl = ");ptn(gnl);pts(" && line ");
			ptn(i);pts(" = ");pts("''");pts(line);pte("''");
			pte("================================================================================");
		}
		ft_strdel(&line);

		// if ((gnl2 = get_next_line(fd2, &line)))
		// {
		// 	pte("================================================================================");
		// 	pts("fd2 = ");ptn(fd2);pts(" gnl2 = ");ptn(gnl2);pts(" && line ");
		// 	ptn(i);pts(" = ");pts("''");pts(line);pte("''");
		// 	pte("================================================================================");
		// }
		// ft_strdel(&line);
		ptcn;

	}
	// ft_strdel(&line);
	close(fd);
	// close(fd2);
	return (0);
}
