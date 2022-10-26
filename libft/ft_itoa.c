/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:50:16 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/10/16 14:18:38 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	conter(int c)
{
	int	i;

	i = 0;
	if (c <= 0)
		i++;
	while (c != 0)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

static void	*filed(int nbr, int size, char *str, int s)
{
	while (size > s)
	{
		str[size - 1] = nbr % 10 + 48;
		nbr = nbr / 10;
		size--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		s;
	int		size;

	size = conter(n);
	s = 0;
	p = malloc(sizeof(char) * size + 1);
	if (!p)
		return (0);
	if (n == -2147483648)
	{
		p[0] = '-';
		p[1] = '2';
		n = 147483648;
		s = 2;
	}
	else if (n < 0)
	{
		p[0] = '-';
		n *= -1;
		s = 1;
	}
	p = filed(n, size, p, s);
	p[size] = 0;
	return (p);
}
