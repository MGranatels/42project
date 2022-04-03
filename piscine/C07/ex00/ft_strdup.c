/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:51:54 by mgranate          #+#    #+#             */
/*   Updated: 2022/02/03 16:35:31 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	ft_lenght(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}	

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	dest = (char *)malloc(ft_lenght(src) * sizeof(char));
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int main()
{
	char src [] = "Olasasfafasdafasgdsgsgasa";
	char *dest;

	printf("%s\n", ft_strdup(src));
}*/
