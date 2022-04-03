/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:36:34 by mgranate          #+#    #+#             */
/*   Updated: 2022/02/02 19:03:08 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
			i++;
	return (s1[i] - s2[i]);
}

void	ft_swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

int	main(int argc, char **argv)
{
	int	qtd;
	int	d;
	int	c;
	int	arg[400];

	c = 1;
	qtd = 1;
	while (qtd < argc)
	{
		arg[qtd] = qtd;
		qtd++;
	}
	while (c < argc)
	{
		d = c;
		while (d < argc)
		{
			if (ft_strcmp(argv[arg[c]], argv[arg[d]]) > 0)
				ft_swap(&arg[c], &arg[d]);
			d++;
		}
		ft_putchar(argv[arg[c++]]);
	}
	return (0);
}
