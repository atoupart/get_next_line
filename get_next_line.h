/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:31:21 by atoupart          #+#    #+#             */
/*   Updated: 2016/02/22 18:58:49 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

# define BUFF_SIZE 999

# define ptn ft_putnbr
# define pts ft_putstr
# define ptcn ft_putchar('\n')

int		get_next_line(int const fd, char **line);

#endif
