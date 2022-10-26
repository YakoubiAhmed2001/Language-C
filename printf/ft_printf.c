/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:27:37 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/10/21 20:16:58 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printforma(const char *format, int len, va_list ap, int i)
{
	if (format[i] == 'c')
		len += ft_putchar((char)va_arg(ap, int));
	if (format[i] == 'd' || format[i] == 'i')
		len += ft_putnbr(va_arg(ap, int));
	if (format[i] == 's')
		len += ft_putstr(va_arg(ap, char *));
	if (format[i] == 'u')
		len += ft_putuns(va_arg(ap, unsigned int));
	if (format[i] == 'x')
		len += ft_puthex(va_arg(ap, unsigned int), "0123456789abcdef");
	if (format[i] == 'X')
		len += ft_puthex(va_arg(ap, unsigned int), "0123456789ABCDEF");
	if (format[i] == '%')
		len += ft_putchar('%');
	if (format[i] == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_puthex(va_arg(ap, unsigned long), "0123456789abcdef");
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	len = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += 1;
			len = ft_printforma(format, len, ap, i);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}

// #include <limits.h>
// int main()
// {
// 	int s = ft_printf("NULL %s NULL", NULL) ;
// 	printf("\n%d\n", s);
// 	int a = printf("NULL %s NULL", NULL);
// 	printf("\n%d", a);
// 	return 0;
// }
