/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_pow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksemele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:32:36 by ksemele           #+#    #+#             */
/*   Updated: 2020/02/03 11:32:37 by ksemele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long int		ft_to_pow(unsigned int base, \
								unsigned long long int pow)
{
	unsigned long long int	res;

	res = 1;
	if (pow == 0)
		return (res);
	if (base == 2)
	{
		while (pow > 0)
		{
			res = res << 1;
			pow--;
		}
	}
	return (res);
}
