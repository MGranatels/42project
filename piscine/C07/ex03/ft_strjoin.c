/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:20:53 by mgranate          #+#    #+#             */
/*   Updated: 2022/02/03 16:27:46 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		g_i;
int		g_j;
int		g_c;
char	*g_dest;

char	*ft_strjoin(int size, char **strs, char *sep)
{
	g_dest = (char *)malloc(sizeof(strs + size));
	if (!g_dest)
		return (NULL);
	g_i = 0;
	g_c = 0;
	while (g_i < size)
	{
		g_j = 0;
		while (strs[g_i][g_j])
		{
			g_dest[g_c] = strs[g_i][g_j];
			g_c++;
			g_j++;
		}
		g_j = 0;
		while (sep[g_j] != '\0' && g_i != size -1)
		{
			g_dest[g_c] = sep[g_j];
			g_c++;
			g_j++;
		}
		g_i++;
	}
	g_dest[g_c] = '\0';
	return (g_dest);
}
/*
int	main(void)
{
	char *strs[9];

	strs[0] = "A";
	strs[1] = "ver";
	strs[2] = "se";
	strs[3] = "esta";
	strs[4] = "merda";
	strs[5] = "vai";
	strs[6] = "dar";
	strs[7] = "certo";
	strs[8] = "caralho";


	printf("%s\n", ft_strjoin(0, strs, " + "));
}*/
