/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception_treat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:28:20 by cghael            #+#    #+#             */
/*   Updated: 2020/01/30 15:28:22 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_set_str(char *str)
{
	char			*tmp;
	int				len;

	len = ft_strlen(str);
	if (!(tmp = ft_strnew((size_t)len)))
		ft_error_exit("Malloc error in ft_f()", NULL);
	tmp = ft_strcpy(tmp, str);
	return (tmp);
}

static char			*ft_expo_ones(t_float res, t_ftptf *tmp_t)
{
	uint64_t		bit;

	bit = 1;
	if ((res.number.mant & bit << 62u) == 0)
	{
		res.number.mant = res.number.mant << 16u;
		res.number.mant = res.number.mant >> 16u;
		if (res.number.mant == 0)
		{
			if (tmp_t->spec == 'F')
				return (ft_set_str("INF"));
			else
				return (ft_set_str("inf"));
		}
	}
	if (tmp_t->spec == 'F')
	{
		tmp_t->nan = 1;
		return (ft_set_str("NAN"));
	}
	else
	{
		tmp_t->nan = 1;
		return (ft_set_str("nan"));
	}
}

char				*ft_exception_treat(t_float res, t_ftptf *tmp_t)
{
	if ((res.number.expo ^ 32767u) == 0)
	{
		tmp_t->zero = 0;
		return (ft_expo_ones(res, tmp_t));
	}
	else
		return (ft_count_float(res, *tmp_t));
}
