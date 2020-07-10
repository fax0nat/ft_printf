/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dothething_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 23:28:57 by yhershel          #+#    #+#             */
/*   Updated: 2020/07/10 21:41:34 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	dothething_d_i(t_specifier *specif, int content_d_i)
{
	int flag;

	if (content_d_i == 0 && specif->accuracy < 0)
		specif->accuracy = 1;
	else if (specif->accuracy < 0)
		specif->accuracy = 0;
	if (specif->width < 0)
		specif->width = 0;
	flag = f_check_flag_d_i(specif, content_d_i);
	if (flag == 2)
		ft_putstr_fd("", 1);
	if (flag == 0)
		ft_putnbr_fd(content_d_i, 1);
	return (0);
}

int	dothething_u(t_specifier *specif, unsigned int content_u)
{
	int		flag;
	char	*fin;

	fin = NULL;
	if (content_u == 0 && specif->accuracy < 0)
		specif->accuracy = 1;
	else if (specif->accuracy < 0)
		specif->accuracy = 0;
	if (specif->width < 0)
		specif->width = 0;
	flag = f_check_flag_u(specif, content_u);
	if (flag == 2)
		ft_putstr_fd("", 1);
	if (flag == 0)
	{
		fin = f_positiv_itoa(content_u);
		ft_putstr_fd(fin, 1);
	}
	free(fin);
	return (0);
}

int	dothething_x(t_specifier *specif, unsigned int content_x)
{
	char	*hex;
	int		flag;

	if (specif->type == 'x')
		hex = f_tolower_str(f_into_hex(content_x, 9));
	else
		hex = f_into_hex(content_x, 9);
	if (content_x == 0)
		hex = "0";
	else
		hex = f_format_pointer(hex);
	flag = f_check_flag_x(specif, hex);
	if (flag == 2)
		ft_putstr_fd("", 1);
	if (flag == 0)
		ft_putstr_fd(hex, 1);
	return (0);
}
