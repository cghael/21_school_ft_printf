/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_div_by_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:21:58 by cghael            #+#    #+#             */
/*   Updated: 2020/02/12 12:22:01 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_div_last(int arr[], int div[], int j, int i)
{
	while (div[i])
	{
		if (div[i] <= 9)
			div[i] -= 1;
		if (div[i] == 0)
			break ;
		arr[j] = div[i] % 10;
		div[i] /= 10;
		j++;
	}
	return (j);
}

static int			ft_div_arr_i(int arr[], int div[], int j, int i)
{
	int		num;

	num = 8;
	while (num)
	{
		arr[j] = div[i] % 10;
		div[i] /= 10;
		j++;
		num--;
	}
	return (j);
}

void				ft_put_div_by_one(int div[])
{
	int		i;
	int		j;
	int		arr[FLOAT_BUFF];

	i = 0;
	j = 0;
	while (i < div[FLOAT_BUFF])
	{
		if (i < div[FLOAT_BUFF] - 1 && j <= FLOAT_BUFF)
			j = ft_div_arr_i(arr, div, j, i);
		else
			j = ft_div_last(arr, div, j, i);
		i++;
	}
	j--;
	i = 0;
	while (j >= 0 && j <= FLOAT_BUFF)
	{
		div[i] = arr[j];
		i++;
		j--;
	}
}
