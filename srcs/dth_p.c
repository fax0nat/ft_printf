/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dth_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:39:18 by yhershel          #+#    #+#             */
/*   Updated: 2020/07/10 22:06:20 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		f_print_pointer(t_specifier *specif, void *content_p)
{
	char *p_hex;

	if (content_p == NULL)
		p_hex = "0";
	else
	{
		p_hex = f_tolower_str(f_into_hex((unsigned long int)content_p, 16));
		p_hex = f_format_pointer(p_hex);
	}
	if (specif->width > 0)
		return (f_print_pointer_2(specif, p_hex));
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(p_hex, 1);
	free(p_hex);
	return (0);
}

int		f_print_pointer_2(t_specifier *specif, char *p_hex)
{
	char *spaces;

	spaces = f_widht(specif, ft_strlen(p_hex) + 2);
	if (ft_strchr(specif->flag, '-'))
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(p_hex, 1);
		ft_putstr_fd(spaces, 1);
	}
	else
	{
		ft_putstr_fd(spaces, 1);
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(p_hex, 1);
	}
	free(p_hex);
	return (0);
}

char	*f_format_pointer(char *p_hex)
{
	int		i;
	int		j;
	int		flag;
	int		len;
	char	*new_p_hex;

	i = 0;
	j = 0;
	flag = 0;
	len = ft_strlen(p_hex);
	new_p_hex = ft_calloc(len + 1, 2);
	while (i < len)
	{
		if (p_hex[i] != '0')
			++flag;
		if (flag > 0)
			new_p_hex[j++] = p_hex[i];
		++i;
	}
	new_p_hex[j] = '\0';
	free(p_hex);
	return (new_p_hex);
}
