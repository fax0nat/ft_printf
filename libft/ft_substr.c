/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 19:07:32 by yhershel          #+#    #+#             */
/*   Updated: 2020/07/10 15:47:01 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	slen;

	i = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return ("");
	if (len > slen)
		len = slen - start;
	if (!(str = (char*)malloc(sizeof(*s) * (len + 1))))
		return (NULL);
	while (i < len && s[i] && start < slen)
	{
		str[i] = s[start];
		++i;
		++start;
	}
	str[i] = 0;
	return (str);
}
