/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_in_def.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:21:25 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/07 12:21:26 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Function moving (*p)ointer, while define line (FLAGS, SIZE and other #define
** in .header) exist.
*/

int		ft_find_in_def(char *define_line, char *p)
{
	p++;
	while (*p && *p != '\0')
	{
		if (ft_strchr(define_line, *p))
			return (1);
		p++;
	}
	return (-1);
}
