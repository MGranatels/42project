/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 23:34:33 by mgranate          #+#    #+#             */
/*   Updated: 2022/03/03 16:09:11 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>

void	first_char_adress(char *first)
{
	uintptr_t num;
	char hex[16];
	int i;

	num = (uintptr_t) first;
	i = 15;
	while(i >= 0)
	{
		hex[i] = "0123456789abcdef"[num%16];
		num /= 16;
		i--;
	}
	write(1, hex, 16);
	write(1, ": ",2);
}

void	ft_putchar(char w)
{
	write(1, &w, 1);
}

void	print_characters(char *str)
{
	int	counter;

	counter = 0;

		while((counter % 16) != 0 || counter == 0)
		{
			if (str[counter] == '\0')
				break ;
			if((str[counter] >= ' ') && (str[counter] != 127))
				write(1, &str[counter], 1);
			else
				write(1, ".", 1);
			counter++;
		}

}

void	count_character_rotation(char *str)
{

	int c;
	int aux;
	int count;
	int count1;


	c = 0;
	count = 0;
	count1 = 0;
	while (str[c] != '\0')
	{
		if (c == 0 || c % 16 == 0)
			first_char_adress(str);
		if (c % 2 == 0 && c != 0)
		{
			write(1, " ", 1);
		}
		aux = str[c];
		ft_putchar("0123456789abcdef"[aux / 16]);
		ft_putchar("0123456789abcdef"[aux % 16]);
		count ++;
		if (count == 16)
		{
			write(1, " ", 1);
			print_characters(&str[count1 * 16]);
			write(1, "\n", 1);
			count = 0;
			count1++;
		}

		c ++;
	}
}

int main()
{
	char str[] = "0123456789ABCDEF 0123456789abcdef 0123";
	count_character_rotation(str);
}

