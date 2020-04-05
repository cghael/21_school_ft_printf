/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:00:01 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/17 13:00:02 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_change_sign(char *tmp, t_ftptf tmp_t)
{
	char			*res;

	if (tmp_t.sign)
	{
		if (tmp_t.sign == ' ' && !tmp_t.minus)
			res = ft_strrchr(tmp, tmp_t.sign);
		else
			res = ft_strchr(tmp, tmp_t.sign);
		*res = '0';
		tmp = ft_strchr(tmp, '0');
		*tmp = tmp_t.sign;
		if (tmp_t.minus_val)
			*tmp = '-';
	}
}

static char			*ft_add_sign(char *tmp, t_ftptf *tmp_t)
{
	char			*res;

	if (tmp_t->sign || tmp_t->plus || tmp_t->spacer)
	{
		res = ft_strnew(ft_strlen(tmp) + 1);
		if (tmp_t->sign == '-')
			tmp_t->minus_val = 1;
		if (tmp_t->spacer)
			tmp_t->sign = ' ';
		if (tmp_t->plus)
			tmp_t->sign = '+';
		*res = tmp_t->sign;
		ft_strcpy(res + 1, tmp);
		free(tmp);
		return (res);
	}
	return (tmp);
}

long double			ft_dollar_float(int n, t_arg *ap_t, t_ftptf tmp_t)
{
	int				i;

	i = 0;
	if (n > 0)
	{
		while (++i < n)
			va_arg(ap_t->d_arg, void*);
		if (tmp_t.l_)
			return (va_arg(ap_t->d_arg, long double));
		else
			return ((long double)va_arg(ap_t->d_arg, double));
	}
	else
	{
		if (tmp_t.l_)
			return (va_arg(ap_t->d_arg, long double));
		else
			return ((long double)va_arg(ap_t->n_arg, double));
	}
}

static char			*ft_add_dot(char *val)
{
	int				val_len;
	char			*tmp;

	val_len = ft_strlen(val);
	if (!(tmp = ft_strnew(val_len + 1)))
		ft_error_exit("gav", NULL);
	ft_strcpy(tmp, val);
	tmp[val_len] = '.';
	free(val);
	return (tmp);
}

void				ft_f(t_arg *ap_t, t_res *buf_t, t_ftptf *tmp_t)
{
	t_float			res;
	char			*tmp;
	int				len;

	res.value = ft_dollar_float(tmp_t->dollar[0], ap_t, *tmp_t);
	if (res.number.sign)
		tmp_t->sign = '-';
	tmp = ft_exception_treat(res, tmp_t);
	tmp = ft_add_sign(tmp, tmp_t);
	len = ft_strlen(tmp);
	if ((tmp_t->octo && tmp_t->spec == 'f' && tmp_t->precision == 0) \
			&& tmp_t->spec != 'G' && tmp_t->spec != 'g')
		tmp = ft_add_dot(tmp);
	if (tmp_t->width > len)
		tmp = ft_width_treat(tmp_t->width, tmp, *tmp_t);
	ft_change_sign(tmp, *tmp_t);
	buf_t->res = tmp;
	if (buf_t->res == NULL)
		ft_error_exit("Malloc error in ft_x()", buf_t);
}
