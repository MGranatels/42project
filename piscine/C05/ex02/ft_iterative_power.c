/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:04:06 by mgranate          #+#    #+#             */
/*   Updated: 2022/02/02 12:34:23 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	sum;

	sum = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		sum *= nb;
		power --;
	}
	return (sum);
}

int main()
{
	printf("%d\n",ft_iterative_power(4, 2));
	printf("%d\n",ft_iterative_power(0, 0));
	printf("%d\n",ft_iterative_power(-1, 5));
}

