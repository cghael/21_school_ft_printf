/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:10:53 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/30 16:10:55 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_fstring		*ft_create_fstring(t_float res)
{
	t_fstring			*tmp;
	char				*str;
	int					exp_abs;

	tmp = (t_fstring*)malloc(sizeof(t_fstring));
	if (!tmp)
		ft_error_exit("Malloc error in ft_create_fstring()", NULL);
	ft_bzero(tmp, sizeof(t_fstring));
	tmp->mant_str = ft_u64toa_base(res.number.mant, 2, 0);
	tmp->exp = res.number.expo - 16382;
	if (tmp->exp < 0)
	{
		exp_abs = ft_abs(tmp->exp);
		if (!(str = ft_strnew(exp_abs + ft_strlen(tmp->mant_str))))
			ft_error_exit("Malloc in ft_create_fstring()", NULL);
		str = ft_memset(str, '0', exp_abs);
		ft_strcpy(str + exp_abs, tmp->mant_str);
		free(tmp->mant_str);
		tmp->mant_str = str;
		tmp->exp = 0;
	}
	return (tmp);
}

char					*ft_count_float(t_float res, t_ftptf tmp_t)
{
	t_fstring			*numb;

	numb = ft_create_fstring(res);
	numb = ft_get_integer(numb);
	if ((res.value != LDBL_MIN && res.value != -LDBL_MIN) || \
			tmp_t.precision >= 4930)
		numb = ft_get_divisional(numb);
	numb = ft_add_float_to_str(numb, tmp_t);
	return (numb->digit_str);
}
