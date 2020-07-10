/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 00:11:44 by yhershel          #+#    #+#             */
/*   Updated: 2020/07/10 16:53:09 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char		*f_strcpy(char *dest, char *src, unsigned int size)
{
	int				i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		++len;
	while (src[i] != '\0' && i < ((int)size - 1))
	{
		dest[i] = src[i];
		++i;
	}
	if (size)
		dest[i] = '\0';
	return (dest);
}

t_specifier	*clean_specif(t_specifier *specif)
{
	specif->percent = ' ';
	specif->flag = "";
	specif->width = 0;
	specif->dot = ' ';
	specif->accuracy = 0;
	specif->type = ' ';
	return (specif);
}

void		f_write_else_str(t_specifier *specif)
{
	if (specif->percent != ' ')
		ft_putchar_fd('%', 1);
	if (ft_strncmp(specif->flag, "", 1) == 0)
		ft_putstr_fd(specif->flag, 1);
	if (specif->width != 0)
		ft_putstr_fd(ft_itoa(specif->width), 1);
	if (specif->dot != ' ')
		ft_putchar_fd('.', 1);
	if (specif->accuracy != 0)
		ft_putstr_fd(ft_itoa(specif->accuracy), 1);
	if (specif->type != ' ')
		ft_putchar_fd(specif->type, 1);
	clean_specif(specif);
}
