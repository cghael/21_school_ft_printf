/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbigger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:51:34 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/17 11:51:36 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_isbigger() compare 2 int a,b and return bigger of them.
*/

int		ft_isbigger(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
