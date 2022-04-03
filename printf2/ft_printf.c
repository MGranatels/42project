/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:41:06 by mgranate          #+#    #+#             */
/*   Updated: 2022/03/03 19:11:04 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/_types/_va_list.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_putchar1(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr1(char *s)
{
	int count;

	count = 0;
	while (s[count])
	{
		write(1, &s[count], 1);
		count++;
	}
	return (count);
}

int	ft_putnumber(int nb)
{
	long int	n;
	int count;
	
	count = 0;
	n = nb;
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
		count++; 
	}
	if (n > 9)
	{
		count += ft_putnumber(n / 10);
		count += ft_putnumber(n % 10);
	}
	else 
		count += ft_putchar1(n + '0');
	return (count);
}

int	ft_putnb_base(unsigned int nb, char x)
{
	int	count;

	count = 0;
	if (nb > 15)
	{
		count += ft_putnb_base(nb / 16, x);
		count += ft_putnb_base(nb % 16, x);
	}
	else
	{
		if (nb < 10)
			count += ft_putchar1(nb + '0');
		else
		{
			if (x == 'X')
				count += ft_putchar1("0123456789ABCDEF"[nb]);
			else
				count += ft_putchar1("0123456789abcdef"[nb]);		
		}	
	} 
	return (count);
}

int	ft_putadress(unsigned long int p)
{
	int	count;

	count = 0;
	if (p > 15)
	{
		count += ft_putadress(p / 16);
		count += ft_putadress(p % 16);
	}
	else
		count += ft_putchar1("0123456789abcdef"[p]);
	return (count);
}

int	ft_search_format(const char *str, va_list *argm, int i)
{
	int count;

	count = 0;
	if (str[i] == 'c')
		count += ft_putchar1(va_arg(*argm, int));
	else if (str[i] == 's')
		count += ft_putstr1(va_arg(*argm, char *));
	return (count);
}

int	ft_printf2(char *str, ...)
{
	va_list argm;
	int	i;
	int count;

	count = 0;
	i = 0;
	va_start(argm, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_search_format(str, &argm, i);
		}
		else
		{
			count++;
			write (1, &str[i], 1);
		}
		i++;
	}
	return (count);
}

int	main()
{
	char c[] = "Hello";
	char p = 'j';
	ft_printf2("%c\n %s", p , c);
}