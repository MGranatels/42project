/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:23:23 by mgranate          #+#    #+#             */
/*   Updated: 2022/01/30 18:18:34 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	n;
	int	a;
	int	i;

	n = 0;
	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[n])
	{
		a = 0;
		while (str[n++] == to_find[a++])
		{
			if (to_find[a] == '\0')
				return (&str [n - a]);
		}
	}
	return (0);
}

int main()
{
	char str [] = "Hello World I am Mario";
	char find [] = "World";
	printf("%s",ft_strstr(str, find));
}

