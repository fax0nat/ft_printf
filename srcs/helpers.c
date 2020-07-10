/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 01:47:27 by yhershel          #+#    #+#             */
/*   Updated: 2020/07/10 22:45:23 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char		*f_stradd(char *str, char ch)
{
	char	*s;
	size_t	i;

	i = 0;
	if (!(s = (char*)malloc(sizeof(str) + 2)))
		return (NULL);
	while (*str)
		s[i++] = *str++;
	s[i++] = ch;
	s[i] = '\0';
	return (s);
}

void		f_bspaces(char *str, int count)
{
	int	i;

	i = 0;
	while (count)
	{
		str[i++] = ' ';
		--count;
	}
	str[i] = '\0';
}

void		f_bzeros(char *str, int count)
{
	int	i;

	i = 0;
	while (count)
	{
		str[i++] = '0';
		--count;
	}
	str[i] = '\0';
}

int			f_countdigit(const char *str)
{
	int i;

	i = 0;
	while (*str <= '9' && *str >= '0')
	{
		++i;
		++str;
	}
	return (i);
}
