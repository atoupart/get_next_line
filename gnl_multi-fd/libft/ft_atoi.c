/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:07:22 by atoupart          #+#    #+#             */
/*   Updated: 2015/12/03 18:08:32 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		nb;
	int		a;

	nb = 0;
	a = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		str++;
		a = -1;
	}
	else if (*str == '+')
		str++;
	while ((*str != 0) && ft_isdigit(*str))
	{
		nb = (nb * 10) + (*str - 48);
		str++;
	}
	if (nb == 0)
		return (0);
	else
		return (nb * a);
}
