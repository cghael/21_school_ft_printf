/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_divisional.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 21:33:06 by ksemele           #+#    #+#             */
/*   Updated: 2020/02/06 21:33:08 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_five_multiple(int multpl[])
{
	int			i;
	int			tmp;

	i = 0;
	tmp = 0;
	while (i < multpl[0])
	{
		multpl[FLOAT_BUFF - i] = multpl[FLOAT_BUFF - i] * 5;
		multpl[FLOAT_BUFF - i] += tmp;
		tmp = 0;
		if (multpl[FLOAT_BUFF - i] / 100000000)
		{
			tmp = multpl[FLOAT_BUFF - i] / 100000000;
			multpl[FLOAT_BUFF - i] = multpl[FLOAT_BUFF - i] % 100000000;
		}
		i++;
	}
	if (tmp && (multpl[FLOAT_BUFF - i] == 0))
		multpl[0]++;
	multpl[FLOAT_BUFF - i] += tmp;
}

static void		ft_multiple_ten(int div_numb[])
{
	int			i;
	int			tmp;

	i = 0;
	tmp = 0;
	while (i < div_numb[FLOAT_BUFF] || tmp)
	{
		div_numb[i] *= 10;
		if (div_numb[i] == 0 && tmp && i == div_numb[FLOAT_BUFF])
			div_numb[FLOAT_BUFF]++;
		div_numb[i] += tmp;
		tmp = 0;
		if (div_numb[i] / 100000000)
		{
			tmp = div_numb[i] / 100000000;
			div_numb[i] = div_numb[i] % 100000000;
		}
		i++;
	}
}

static void		ft_five_plus(const int multpl[], int div_numb[])
{
	int			i;
	int			tmp;

	i = 0;
	tmp = 0;
	while (i <= div_numb[FLOAT_BUFF] && i < FLOAT_BUFF)
	{
		if (div_numb[i] == 0 && (multpl[FLOAT_BUFF - i] || tmp) && \
				i == div_numb[FLOAT_BUFF])
			div_numb[FLOAT_BUFF]++;
		div_numb[i] += multpl[FLOAT_BUFF - i];
		div_numb[i] += tmp;
		tmp = 0;
		if (div_numb[i] / 100000000)
		{
			tmp = div_numb[i] / 100000000;
			div_numb[i] = div_numb[i] % 100000000;
		}
		i++;
	}
}

/*
** fill numb->div_numb numbers with numbers in base 10.
*/

t_fstring		*ft_get_divisional(t_fstring *numb)
{
	char		*start;
	char		*end;
	int			multpl[FLOAT_BUFF + 1];

	start = &numb->mant_str[numb->exp];
	end = start;
	end = ft_strrchr(end, '1');
	if (end < start)
		return (numb);
	ft_bzero(multpl, sizeof(multpl));
	multpl[FLOAT_BUFF] = 1;
	multpl[0] = 1;
	numb->div_numb[0] = 1;
	numb->div_numb[FLOAT_BUFF] = 1;
	while (start <= end)
	{
		ft_five_multiple(multpl);
		ft_multiple_ten(numb->div_numb);
		if (*start == '1')
			ft_five_plus(multpl, numb->div_numb);
		start++;
	}
	return (numb);
}
