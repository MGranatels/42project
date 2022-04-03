/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:29:32 by mgranate          #+#    #+#             */
/*   Updated: 2022/01/25 17:43:07 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_rev_int_tab(int *tab, int size)
{
	int	first;
	int	last;
	int	aux;

	first = 0;
	last = size - 1;
	while (last >= first)
	{
		aux = tab[last];
		tab[last] = tab[first];
		tab[first] = aux;
		first++;
		last--;
	}
}
