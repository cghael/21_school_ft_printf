/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 10:52:31 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/17 10:52:46 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** DESCRIPTION
** ft_abs() calculate ABS of int i;
** unsigned int res calculate correct ABS in unsigned range
** if (res > INT32_MAX) return INT32_MIN
*/

int						ft_abs(int i)
{
	unsigned int		res;

	res = i;
	if (i < 0)
		res = -res;
	return (res);
}
