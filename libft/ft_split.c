/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:30:15 by ayakoubi          #+#    #+#             */
/*   Updated: 2022/10/15 11:00:32 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char const *str, char c)
{
	int	i;
	int	word;

	word = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i + 1] == c || str[i + 1] == 0) && str[i] != c)
			word++;
		i++;
	}
	return (word);
}

static int	ft_strcpy(char *dest, char const *src, char c)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

static int	ft_strlen_e(const char *s, char c)
{
	int	i;

	i = -1;
	while (s[++i] && s[i] != c)
		;
	return (i);
}

static char	**slice(const char *s, char c, char **new)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			new[index] = (char *) malloc(ft_strlen_e(&s[i], c) + 1);
			if (!new[index])
				return (0);
			i += ft_strcpy(new[index], &s[i], c);
			index++;
		}
	}
	new[index] = 0;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		wc;
	char	**dst;

	i = 0;
	if (!s)
		return (0);
	wc = ft_check(s, c);
	dst = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!dst)
		return (0);
	slice(s, c, dst);
	return (dst);
}
