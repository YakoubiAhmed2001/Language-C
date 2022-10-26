/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:07:03 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/10/15 12:21:07 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*newstr;

	size = len + 1;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		newstr = malloc(1);
		newstr[0] = 0;
		return (newstr);
	}
	i = 0;
	j = start;
	newstr = malloc(size);
	if (!newstr)
		return (NULL);
	while (j < len + start)
		newstr[i++] = s[j++];
	newstr[i] = '\0';
	return (newstr);
}
