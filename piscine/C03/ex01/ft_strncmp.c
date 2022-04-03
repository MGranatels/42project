/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:54:06 by mgranate          #+#    #+#             */
/*   Updated: 2022/02/03 16:15:04 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	c;

	c = 0;
	while (c < (n - 1) && (s1[c] != '\0') && (s2[c] != '\0') && s1[c] == s2[c])
		c++;
	if (n == 0)
		return (0);
	else
		return (s1[c] - s2[c]);
}
/*
int main ()
{
	char s1 [] = "Hello";
	char s2 [] = "Hello";
	printf("%d\n",ft_strncmp(s1, s2, 1));
}*/
