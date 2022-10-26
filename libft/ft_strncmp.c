/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:51:17 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/10/15 11:30:38 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*cstr1;
	unsigned char	*cstr2;

	cstr1 = (unsigned char *) str1;
	cstr2 = (unsigned char *) str2;
	i = -1;
	while (++i < n && (cstr1[i] || cstr2[i]))
	{
		if (cstr1[i] > cstr2[i])
			return (1);
		if (cstr1[i] < cstr2[i])
			return (-1);
	}
	return (0);
}
