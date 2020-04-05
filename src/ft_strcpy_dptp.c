/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_dptp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:41:55 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/18 14:41:58 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** DESCRIPTION
** ft_strcpy_dptp() take 3 pointers:
** START (*src), END (*end) & DESTINATION (*dst)
** copy all symbols from START to END into DESTINATION and finish it by '\0'
** RETURN VALUES
** pointer to '\0' of DESTINATION or NULL
*/

char		*ft_strcpy_dptp(char *dst, char *src, char *end)
{
	if (!dst || !src || !end)
		return (NULL);
	while (src != end)
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
	return (dst);
}
