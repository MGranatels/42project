/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:53:05 by mgranate          #+#    #+#             */
/*   Updated: 2022/01/30 14:52:05 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_sort_int_tab(int *tab, int size)
{
	int	p1;
	int	p2;
	int	temp;

	p1 = 0;
	while (p1 < size)
	{
		p2 = 0;
		while (p2 < size - 1)
		{
			if (tab[p2] > tab[p2 + 1])
			{
				temp = tab[p2];
				tab[p2] = tab[p2 + 1];
				tab[p2 + 1] = temp;
			}
			p2++;
		}
		p1++;
	}
}
