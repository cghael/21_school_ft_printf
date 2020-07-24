/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:59:37 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/17 12:59:38 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_change_sign(char *tmp, t_ftptf tmp_t)
{
	char		*res;

	if (tmp_t.sign)
	{
		if (tmp_t.sign == ' ' && !tmp_t.minus)
			res = ft_strrchr(tmp, tmp_t.sign);
		else
			res = ft_strchr(tmp, tmp_t.sign);
		*res = '0';
		tmp = ft_strchr(tmp, '0');
		*tmp = tmp_t.sign;
	}
}

static char		*ft_add_sign(char *tmp, t_ftptf *tmp_t)
{
	char			*res;

	if (tmp_t->sign || tmp_t->plus || tmp_t->spacer)
	{
		res = ft_strnew(ft_strlen(tmp) + 1);
		if (tmp_t->sign == '-')
			tmp_t->minus_val = 1;
		else if (tmp_t->plus)
			tmp_t->sign = '+';
		else if (tmp_t->spacer)
			tmp_t->sign = ' ';
		*res = tmp_t->sign;
		ft_strcpy(res + 1, tmp);
		free(tmp);
		return (res);
	}
	return (tmp);
}

static char		ft_type_sign(t_ftptf tmp_t, void *val)
{
	if (tmp_t.l)
	{
		if ((long int)val < 0)
			return ('-');
	}
	else if (tmp_t.ll)
	{
		if ((long long int)val < 0)
			return ('-');
	}
	else if (tmp_t.h)
	{
		if ((short)val < 0)
			return ('-');
	}
	else if (tmp_t.hh)
	{
		if ((signed char)val < 0)
			return ('-');
	}
	else if ((int)val < 0)
		return ('-');
	return ('\0');
}

void			ft_di(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t)
{
	void		*val;
	int			len;
	char		*tmp;

	val = ft_dollar_arg(tmp_t->dollar[0], ap_t);
	if ((long long int)val == 0)
		tmp_t->arg_zero = 1;
	tmp_t->sign = ft_type_sign(*tmp_t, val);
	tmp = ft_num_to_str(val, *tmp_t, 0);
	tmp = ft_precision_treat(tmp, *tmp_t);
	tmp = ft_add_sign(tmp, tmp_t);
	len = ft_strlen(tmp);
	if (tmp_t->width > len)
		tmp = ft_width_treat(tmp_t->width, tmp, *tmp_t);
	ft_change_sign(tmp, *tmp_t);
	buf_t->res = tmp;
	if (buf_t->res == NULL)
		ft_error_exit("Malloc error in ft_x()", buf_t);
}
