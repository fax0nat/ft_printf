/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 14:18:45 by yhershel          #+#    #+#             */
/*   Updated: 2020/06/09 20:33:22 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_wrds(const char *s, char c)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (*s)
	{
		if (j == 1 && *s == c)
			j = 0;
		if (j == 0 && *s != c)
		{
			j = 1;
			i++;
		}
		s++;
	}
	return (i);
}

static size_t	str_len(const char *s, const char c)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

void			*free_mem(char **result)
{
	size_t	i;

	i = 0;
	while (result[i++])
		free(result[i]);
	free(result);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	int		nb;
	int		i;
	int		len;

	i = 0;
	if (!s)
		return (NULL);
	nb = nb_wrds(s, c);
	if (!(result = (char**)malloc(sizeof(char *) * (nb + 1))))
		return (NULL);
	while (i < nb)
	{
		while (*s && *s == c)
			s++;
		len = str_len(s, c);
		if (!(result[i] = ft_substr(s, 0, len)))
			return (free_mem(result));
		s += len;
		i++;
	}
	result[nb] = (NULL);
	return (result);
}
