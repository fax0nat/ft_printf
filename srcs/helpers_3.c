/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 00:11:47 by yhershel          #+#    #+#             */
/*   Updated: 2020/07/10 23:14:45 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char		*f_into_hex(unsigned long int number, int len)
{
	char	*hex;

	if (!(hex = (char*)malloc(len + 1)))
		return (NULL);
	hex[len] = '\0';
	return (f_into_hex_2(number, len, hex));
}

char		*f_into_hex_2(unsigned long int number, int len, char *hex)
{
	int r;
	int i;

	while (number >= 16 && len != 0)
	{
		r = number % 16;
		if (r >= 10)
			hex[--len] = r + 55;
		else
			hex[--len] = r + 48;
		number /= 16;
	}
	if (len > 0)
	{
		if (number >= 10)
			hex[--len] = number + 55;
		else
			hex[--len] = number + 48;
		i = len - 1;
		while (i >= 0)
			hex[i--] = 48;
	}
	return (hex);
}

char		*f_tolower_str(char *str)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		++i;
	}
	return (str);
}

char		*f_positiv_itoa(unsigned int n)
{
	char			ret[11];
	char			*r;
	unsigned int	neg;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	neg = n < 0 ? -1 : 1;
	while (neg * n > 9 || neg * n < 0)
	{
		ret[i++] = '0' + neg * (n % 10);
		n = n / 10;
	}
	ret[i++] = '0' + neg * n;
	if (neg < 0)
		ret[i++] = '-';
	if ((r = (char *)malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	r[i] = '\0';
	while (i--)
		r[i] = ret[j++];
	return (r);
}
