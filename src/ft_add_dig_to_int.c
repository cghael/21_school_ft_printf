/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_dig_to_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:26:40 by ksemele           #+#    #+#             */
/*   Updated: 2020/02/07 19:26:41 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fstring		*ft_add_dig_to_int(t_fstring *numb)
{
	int			i;

	i = 0;
	while (i < FLOAT_BUFF)
	{
		if (numb->int_numb[FLOAT_BUFF - i] + 1 > 999999999)
		{
			numb->int_numb[FLOAT_BUFF - i] = 0;
			i++;
		}
		else
		{
			numb->int_numb[FLOAT_BUFF - i]++;
			return (numb);
		}
	}
	return (numb);
}
