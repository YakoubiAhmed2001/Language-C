/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:18:27 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/10/15 12:42:10 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cheack(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	lens;
	char	*new;
	char	*p;

	if (!s1 || !set)
		return (0);
	i = 0;
	p = (char *)s1;
	lens = ft_strlen(s1) - 1;
	if (!p)
		return (0);
	while (p[i] && ft_cheack(set, p[i]))
			i++;
	while (lens > 0 && ft_cheack(set, p[lens]))
		lens--;
	new = ft_substr(p, i, lens - i + 1);
	return (new);
}
