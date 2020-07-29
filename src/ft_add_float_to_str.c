/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_float_to_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:02:40 by cghael            #+#    #+#             */
/*   Updated: 2020/02/12 12:02:43 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_check_non_zero(const int arr[], int index, int size)
{
	int					i;

	i = index;
	while (i < size)
	{
		if (arr[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

static t_fstring	*ft_get_round(t_fstring *numb)
{
	if (!(numb->div_numb[0] == 5 && \
			(numb->int_numb[FLOAT_BUFF] + 1) % 2 && \
			ft_check_non_zero(numb->div_numb, 1, FLOAT_BUFF + 1)))
	{
		numb = ft_add_dig_to_int(numb);
		numb->digit_str = ft_integer_to_str(numb);
	}
	return (numb);
}

t_fstring			*ft_add_float_to_str(t_fstring *numb, t_ftptf tmp_t)
{
	char				*tmp;
	char				*final_str;

	numb->digit_str = ft_integer_to_str(numb);
	ft_put_div_by_one(numb->div_numb);
	if (tmp_t.dot && tmp_t.precision == 0)
	{
		if (numb->div_numb[0] >= 5)
			numb = ft_get_round(numb);
		return (numb);
	}
	if (!tmp_t.precision)
		return (numb);
	tmp = ft_round_float(numb, tmp_t);
	if (!(final_str = ft_strjoin(numb->digit_str, tmp)))
		ft_error_exit("Malloc error in ft_add_float_to_str\n", NULL);
	free(tmp);
	free(numb->digit_str);
	numb->digit_str = final_str;
	return (numb);
}
