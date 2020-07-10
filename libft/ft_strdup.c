/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 13:19:24 by yhershel          #+#    #+#             */
/*   Updated: 2020/06/09 20:33:22 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*str;
	size_t		i;
	size_t		slen;

	i = 0;
	slen = ft_strlen(s);
	if (!s)
		return (char*)s;
	if (!(str = (char*)malloc(sizeof(*s) + slen)))
		return (0);
	while (i < slen)
	{
		str[i] = s[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}
