/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 17:29:18 by yhershel          #+#    #+#             */
/*   Updated: 2020/06/09 20:33:22 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	int		counter;

	counter = 0;
	if (!s1 || !s2)
		return (0);
	if (!(final = (char *)malloc(sizeof(char) * (ft_strlen((char*)s1) +
ft_strlen((char*)s2) + 1))))
		return (0);
	while (*s1)
	{
		final[counter] = *s1;
		s1++;
		counter++;
	}
	while (*s2)
	{
		final[counter] = *s2;
		s2++;
		counter++;
	}
	final[counter] = 0;
	return (final);
}
