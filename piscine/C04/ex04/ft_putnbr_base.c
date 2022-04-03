/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:18:59 by mgranate          #+#    #+#             */
/*   Updated: 2022/01/31 20:01:21 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_lenght(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base_condition(char *str)
{
	int	j;
	int	i;

	i = 0;
	if (check_lenght(str) <= 1)
		return (0);
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_size;
	long trans = nbr;

	if (check_base_condition(base))
	{
		base_size = check_lenght(base);
		{
			if (trans < 0)
			{
				write(1, "-", 1);
				trans *= -1;
			}
			if (trans >= base_size)
			{
				ft_putnbr_base(trans / base_size, base);
				ft_putnbr_base(trans % base_size, base);
			}
			else
				write(1, &base[trans % base_size], 1);
		}
	}
}

int main()
{
	ft_putnbr_base(-2147483648, "0123456789");
}
