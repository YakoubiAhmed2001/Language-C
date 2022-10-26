/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:12:01 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/10/21 12:46:29 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	counter(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ft_puthex(unsigned long int nbr, char *base)
{
	int	len;
	int	a;

	a = 0;
	len = 0;
	while (base[a])
		a++;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr / a)
		len = ft_puthex(nbr / a, base);
	ft_putchar(base[nbr % a]);
	len += counter(len);
	return (len);
}
