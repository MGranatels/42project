/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:04:04 by mgranate          #+#    #+#             */
/*   Updated: 2022/02/02 18:21:14 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	c;
	int	count;

	c = 0;
	while (str[c] != '\0')
	{
		if ((str[c] >= ' ') && (str[c] != 127))
		{
			ft_putchar(str[c]);
		}
		else
		{
			count = str[c];
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[count / 16]);
			ft_putchar("0123456789abcdef"[count % 16]);
		}
		c++;
	}
	write(1, "\n", 1);
}

write(1, "012345689abcdef"[40 / 16]);
write(1, "012345689abcdef"[40 % 16]);

