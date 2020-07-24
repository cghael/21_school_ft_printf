/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:06:49 by cghael            #+#    #+#             */
/*   Updated: 2020/02/04 18:06:52 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_two_multiple(int multpl[])
{
	int				i;
	int				tmp;

	i = 0;
	tmp = 0;
	while (i < multpl[0])
	{
		multpl[FLOAT_BUFF - i] = multpl[FLOAT_BUFF - i] * 2;
		multpl[FLOAT_BUFF - i] += tmp;
		tmp = 0;
		if (multpl[FLOAT_BUFF - i] / 1000000000)
		{
			tmp = multpl[FLOAT_BUFF - i] / 1000000000;
			multpl[FLOAT_BUFF - i] = multpl[FLOAT_BUFF - i] % 1000000000;
		}
		i++;
	}
	if (tmp && (multpl[FLOAT_BUFF - i] == 0))
		multpl[0]++;
	multpl[FLOAT_BUFF - i] += tmp;
}

static void			ft_two_plus(const int multpl[], int int_numb[])
{
	int				i;
	int				tmp;

	i = 0;
	tmp = 0;
	while (i < multpl[0])
	{
		int_numb[FLOAT_BUFF - i] += multpl[FLOAT_BUFF - i];
		int_numb[FLOAT_BUFF - i] += tmp;
		tmp = 0;
		if (int_numb[FLOAT_BUFF - i] / 1000000000)
		{
			tmp = int_numb[FLOAT_BUFF - i] / 1000000000;
			int_numb[FLOAT_BUFF - i] = int_numb[FLOAT_BUFF - i] % 1000000000;
		}
		i++;
	}
	int_numb[FLOAT_BUFF - i] += tmp;
}

/*
** DESCRIPTION
** ft_get_integer() start from 1st byte in divisional part of mantissa and
** calculate all integer part in left side of mantissa <-
** to visualise:
** replace 5 string to this 3 strings:
** 		ft_printf(("numb->:\t%s\n"), numb->mant_str);
** 		tmp = &numb->mant_str[numb->exp - 1];
** 		ft_printf(("tmp:\t%s\n"), tmp);
*/

t_fstring			*ft_get_integer(t_fstring *numb)
{
	int				i;
	int				multpl[FLOAT_BUFF + 1];
	char			*tmp;

	if (numb->exp < 1)
		return (numb);
	tmp = &numb->mant_str[numb->exp - 1];
	ft_bzero(multpl, sizeof(multpl));
	i = 0;
	while (i < numb->exp && tmp >= numb->mant_str)
	{
		if (i == 0)
		{
			multpl[FLOAT_BUFF] = 1;
			multpl[0] = 1;
		}
		else
			ft_two_multiple(multpl);
		if (*tmp == '1')
			ft_two_plus(multpl, numb->int_numb);
		i++;
		tmp--;
	}
	return (numb);
}
