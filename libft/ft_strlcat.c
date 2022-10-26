/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:48:11 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/10/15 11:04:30 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (dest == 0 && size == 0)
		return (ft_strlen(src));
	i = ft_strlen((const char *)dest);
	j = ft_strlen(src);
	if (size <= i)
		return (j + size);
	k = 0;
	while (src[k] != '\0' && i < size - 1)
	{
		dest[i + k] = src[k];
		k++;
		size--;
	}
	dest[i + k] = '\0';
	return (i + j);
}
