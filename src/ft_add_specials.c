/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_specials.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:07:47 by cghael            #+#    #+#             */
/*   Updated: 2020/01/23 17:07:49 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_add_specials(char *res, t_ftptf tmp_t)
{
	char	*ptr;

	if (tmp_t.spec == 'x' || tmp_t.spec == 'X')
	{
		if (tmp_t.octo && !tmp_t.arg_zero)
		{
			ptr = ft_strchr(res, '0') + 1;
			*ptr = tmp_t.spec;
		}
	}
	else
	{
		if (tmp_t.octo)
		{
			ptr = ft_strchr(res, '0') + 1;
			*ptr = 'x';
		}
	}
}
