/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:55:46 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/10/15 11:09:08 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	while (src[++j])
		;
	if (dstsize == 0)
		return (j);
	else
	{
		while (src[++i] && i < dstsize - 1)
			dest[i] = src[i];
		dest[i] = '\0';
	}
	return (j);
}
