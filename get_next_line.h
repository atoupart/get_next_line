/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:31:21 by atoupart          #+#    #+#             */
/*   Updated: 2016/02/25 17:38:00 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/syslimits.h>

# define BUFF_SIZE 28

# define ptc ft_putchar
# define ptn ft_putnbr
# define pts ft_putstr
# define pte ft_putendl
# define ptcn ft_putchar('\n')

int		get_next_line(int const fd, char **line);

#endif
