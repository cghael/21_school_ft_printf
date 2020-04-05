/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_treat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:40:06 by cghael            #+#    #+#             */
/*   Updated: 2020/01/21 17:40:08 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_len_count(int len, t_ftptf tmp_t)
{
	if (tmp_t.arg_zero && tmp_t.dot && tmp_t.precision == 0)
	{
		len = 0;
		if (tmp_t.spec == 'o' && tmp_t.octo)
			len++;
		if ((tmp_t.spec == 'd' || tmp_t.spec == 'i') && \
					tmp_t.arg_zero && tmp_t.sign)
			len++;
	}
	if (tmp_t.spec == 'o' && tmp_t.arg_zero && tmp_t.octo && !tmp_t.dot)
		len = 1;
	if (tmp_t.precision > len)
	{
		len = tmp_t.precision;
	}
	if ((tmp_t.octo && !tmp_t.arg_zero) || tmp_t.spec == 'p')
	{
		if (tmp_t.spec == 'x' || tmp_t.spec == 'X' || tmp_t.spec == 'p')
			len += 2;
	}
	return (len);
}

static char		*ft_str_with_precision(int len, char *tmp, t_ftptf tmp_t)
{
	char		*res;

	len = ft_len_count(len, tmp_t);
	if (!(res = ft_strnew(len)))
		return (NULL);
	res = ft_memset(res, '0', len);
	if ((tmp_t.spec == 'd' || tmp_t.spec == 'i') && \
				tmp_t.arg_zero && tmp_t.sign)
		*res = *tmp;
	else
		ft_strcpy(res + (len - ft_strlen(tmp)), tmp);
	free(tmp);
	return (res);
}

char			*ft_precision_treat(char *tmp, t_ftptf tmp_t)
{
	int			len;
	char		*res;

	len = ft_strlen(tmp);
	res = ft_str_with_precision(len, tmp, tmp_t);
	if (res == NULL)
		ft_error_exit("Malloc error in ft_x()", NULL);
	return (res);
}
