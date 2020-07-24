/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_treat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:34:49 by cghael            #+#    #+#             */
/*   Updated: 2020/01/21 17:34:53 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_width_treat(int len, char *val, t_ftptf tmp_t)
{
	char	*str_begin;
	char	*tmp;
	int		val_len;
	char	spacer;

	if (!(tmp = ft_strnew(len)))
		return (NULL);
	val_len = ft_strlen(val);
	if ((tmp_t.zero && !tmp_t.minus && !tmp_t.dot) \
			|| (tmp_t.zero && !tmp_t.minus && tmp_t.spec == 'f'))
		spacer = '0';
	else
		spacer = ' ';
	ft_memset(tmp, spacer, len);
	if (tmp_t.minus == 1)
		ft_strncpy(tmp, val, val_len);
	str_begin = tmp + (len - val_len);
	if (tmp_t.minus == 0)
		ft_strncpy(str_begin, val, val_len);
	free((void*)val);
	return (tmp);
}
