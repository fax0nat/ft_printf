/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 08:00:24 by yhershel          #+#    #+#             */
/*   Updated: 2020/07/10 22:59:38 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*f_widht(t_specifier *specif, int len)
{
	char	*spaces;
	int		spaces_count;

	spaces_count = specif->width - len;
	if (spaces_count <= 0)
		return ("");
	if (!(spaces = (char*)malloc(spaces_count + 1)))
		return (NULL);
	f_bspaces(spaces, spaces_count);
	return (spaces);
}

char	*f_put_zeros(t_specifier *specif, int len)
{
	char	*zeros;
	int		zeros_count;

	zeros_count = specif->width - len;
	if (zeros_count <= 0)
		return ("");
	if (!(zeros = (char*)malloc(zeros_count + 1)))
		return (NULL);
	f_bzeros(zeros, zeros_count);
	return (zeros);
}

char	*f_put_zeros_accurcy(t_specifier *specif, int len)
{
	char	*zeros;
	int		zeros_count;

	zeros_count = specif->accuracy - len;
	if (zeros_count <= 0)
		return ("");
	if (!(zeros = (char*)malloc(zeros_count + 1)))
		return (NULL);
	f_bzeros(zeros, zeros_count);
	return (zeros);
}

char	*f_put_accuracy_s(t_specifier *specif, char *str)
{
	char	*new_str;
	int		counter;
	int		i;

	i = 0;
	counter = specif->accuracy;
	if (!(new_str = (char*)malloc(ft_strlen(str) + 1)))
		return (NULL);
	if (counter > (int)ft_strlen(str) || counter < 0)
		return (str);
	else
	{
		while (counter)
		{
			new_str[i] = str[i];
			++i;
			--counter;
		}
		new_str[i] = '\0';
		return (new_str);
	}
	return (str);
}
