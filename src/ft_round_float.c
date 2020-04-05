/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 21:36:21 by ksemele           #+#    #+#             */
/*   Updated: 2020/02/06 21:36:22 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_fstring		*ft_add_dig(t_fstring *numb, int round_dig)
{
	while (round_dig >= 0)
	{
		if (numb->div_numb[round_dig] + 1 > 9)
		{
			numb->div_numb[round_dig] = 0;
			if (round_dig == 0)
			{
				numb = ft_add_dig_to_int(numb);
				numb->digit_str = ft_integer_to_str(numb);
			}
			round_dig--;
		}
		else
		{
			numb->div_numb[round_dig]++;
			return (numb);
		}
	}
	return (numb);
}

static char				*ft_div_to_str(t_fstring *numb, t_ftptf tmp_t)
{
	char				*tmp;
	char				*res;
	int					i;

	i = 0;
	if (!(tmp = (char*)malloc(tmp_t.precision + 2)))
		ft_error_exit("Error malloc in ft_div_to_str\n", NULL);
	res = tmp;
	*tmp = '.';
	tmp++;
	while (i < tmp_t.precision)
	{
		*tmp = (char)(numb->div_numb[i] + '0');
		i++;
		tmp++;
	}
	*tmp = '\0';
	return (res);
}

static int				ft_check_non_zero(const int arr[], int index, int size)
{
	int					i;

	i = index;
	while (i < size)
	{
		if (arr[i] != 0)
			return (1);
		i++;
	}
	return (0);
}

char					*ft_round_float(t_fstring *numb, t_ftptf tmp_t)
{
	int					start;
	int					round_dig;

	start = tmp_t.precision;
	round_dig = start - 1;
	if (numb->div_numb[start] < 5)
		return (ft_div_to_str(numb, tmp_t));
	while (start <= FLOAT_BUFF)
	{
		if (numb->div_numb[start] > 0)
		{
			if (numb->div_numb[start] == 5 && \
				(numb->div_numb[round_dig] + 1) % 2 && \
				!ft_check_non_zero(numb->div_numb, start + 1, FLOAT_BUFF + 1))
				return (ft_div_to_str(numb, tmp_t));
			numb = ft_add_dig(numb, round_dig);
			return (ft_div_to_str(numb, tmp_t));
		}
		start++;
	}
	if ((numb->div_numb[round_dig] + 1) % 2 == 0)
		numb->div_numb[round_dig]++;
	else
		numb->div_numb[round_dig]--;
	return (ft_div_to_str(numb, tmp_t));
}
