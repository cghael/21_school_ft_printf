/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 20:36:33 by ksemele           #+#    #+#             */
/*   Updated: 2020/01/07 20:36:34 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** DESCRIPTION
** ft_strpcpy() take a pointer to char *start and pointer to *end in same line
** then copy all symbols from *start to *end, place '\0' in tmp line.
** RETURN VALUES
** char *head
*/

char		*ft_strpcpy(char *start, char *end)
{
	char	*tmp;
	char	*head;

	if (!(tmp = ft_strdup(start)))
		return (NULL);
	head = tmp;
	while (start != end)
	{
		start++;
		tmp++;
	}
	*tmp = '\0';
	return (head);
}
