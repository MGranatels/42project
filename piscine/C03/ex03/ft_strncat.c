/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:45:11 by mgranate          #+#    #+#             */
/*   Updated: 2022/02/03 16:09:04 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	c;
	int	b;

	c = 0;
	b = 0;
	while (dest[c] != '\0')
		c++;
	while (src[b] != '\0' && nb > 0)
	{
		dest[c] = src [b];
		c++;
		b++;
		nb--;
	}
	dest[c] = '\0';
	return (dest);
}
