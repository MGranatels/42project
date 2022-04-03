/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:19:17 by mgranate          #+#    #+#             */
/*   Updated: 2022/01/31 19:10:00 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_sqrt(int nb)
{
	long	nu;

	nu = 0;
	while (nu * nu <= nb)
	{
		if ((nu * nu) == nb)
			return (nu);
		nu ++;
	}
	return (0);
}

int main()
{
    printf("%d\n", ft_sqrt(1));
    printf("%d\n", ft_sqrt(2147483647));
    printf("%d\n", ft_sqrt(4));
    printf("%d\n", ft_sqrt(2));
    printf("%d\n", ft_sqrt(-20));
}
