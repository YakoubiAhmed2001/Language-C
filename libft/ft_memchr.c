/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:53:20 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/10/15 10:56:31 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	char	*nstr;

	nstr = (char *)str;
	i = -1;
	while (++i < n)
	{
		if (nstr[i] == (char)c)
			return ((void *)&nstr[i]);
	}
	return (NULL);
}
