/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 23:22:46 by yhershel          #+#    #+#             */
/*   Updated: 2020/06/09 20:33:22 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int		i;
	unsigned int		len;

	i = 0;
	len = 0;
	while (dest[len] && len < size)
		++len;
	i = len;
	while (src[len - i] && len + 1 < size)
	{
		dest[len] = src[len - i];
		++len;
	}
	if (i < size)
		dest[len] = '\0';
	return (i + ft_strlen(src));
}
