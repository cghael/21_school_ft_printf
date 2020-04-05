/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:38:33 by cghael            #+#    #+#             */
/*   Updated: 2020/01/21 17:38:35 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_unsign_num(void *val, t_ftptf tmp_t, int l_size)
{
	char		*tmp;

	if (tmp_t.hh)
		tmp = ft_u64toa_base((unsigned char)val, tmp_t.base, l_size);
	else if (tmp_t.h)
		tmp = ft_u64toa_base((unsigned short)val, tmp_t.base, l_size);
	else if (tmp_t.l)
		tmp = ft_u64toa_base((unsigned long)val, tmp_t.base, l_size);
	else if (tmp_t.ll)
		tmp = ft_u64toa_base((unsigned long long)val, tmp_t.base, l_size);
	else
		tmp = ft_u64toa_base((unsigned int)val, tmp_t.base, l_size);
	return (tmp);
}

static char		*ft_sign_num(void *val, t_ftptf tmp_t, int l_size)
{
	char		*tmp;
	char		*tmp_no_sign;

	if (tmp_t.hh)
		tmp = ft_i64toa_base((char)val, tmp_t.base, l_size);
	else if (tmp_t.h)
		tmp = ft_i64toa_base((short)val, tmp_t.base, l_size);
	else if (tmp_t.l)
		tmp = ft_i64toa_base((long)val, tmp_t.base, l_size);
	else if (tmp_t.ll)
		tmp = ft_i64toa_base((long long)val, tmp_t.base, l_size);
	else
		tmp = ft_i64toa_base((int)val, tmp_t.base, l_size);
	if (*tmp == '-')
	{
		tmp_no_sign = ft_strdup(tmp + 1);
		free(tmp);
		return (tmp_no_sign);
	}
	return (tmp);
}

char			*ft_num_to_str(void *val, t_ftptf tmp_t, int l_size)
{
	char *tmp;

	if (tmp_t.spec == 'd' || tmp_t.spec == 'i')
		tmp = ft_sign_num(val, tmp_t, l_size);
	else
		tmp = ft_unsign_num(val, tmp_t, l_size);
	if (tmp == NULL)
		ft_error_exit("Malloc error in ft_x()", NULL);
	return (tmp);
}
