/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 19:48:22 by yhershel          #+#    #+#             */
/*   Updated: 2020/07/05 17:51:02 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int				i;
	unsigned int	len;

	i = 0;
	len = 0;
	if (!dest)
		return (len);
	while (src[len] != '\0')
		++len;
	while (src[i] != '\0' && i < ((int)size - 1))
	{
		dest[i] = src[i];
		++i;
	}
	if (size)
		dest[i] = '\0';
	return (len);
}
