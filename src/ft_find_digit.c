/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:45:52 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/07 12:45:53 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Function moving (*p)ointer, while (**p) is a digit
*/

int		ft_find_digit(char **p)
{
	while (**p && **p != '\0')
	{
		if (ft_isdigit(**p))
			(*p)++;
		else
			return (1);
	}
	return (-1);
}
