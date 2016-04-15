/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:06:14 by atoupart          #+#    #+#             */
/*   Updated: 2015/12/11 18:12:50 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t n)
{
	void	*s;

	s = malloc(sizeof(*s) * n);
	if (!s)
		return (s);
	if (s)
	{
		ft_bzero(s, n);
		return (s);
	}
	else
		return (NULL);
}
