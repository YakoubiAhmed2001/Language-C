/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 01:40:40 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/10/15 10:58:37 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (src == dest)
		return (dest);
	if (src > dest)
		ft_memcpy(dest, src, n);
	if (src < dest)
	{
		while (n-- > 0)
			*((char *) dest + n) = *((char *) src + n);
	}
	return (dest);
}
