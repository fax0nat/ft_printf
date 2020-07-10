/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dth_prc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 06:55:18 by yhershel          #+#    #+#             */
/*   Updated: 2020/07/10 03:25:10 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	f_check_flag_prc(t_specifier *specif, char prc)
{
	char	*spaces_zeros;
	int		flag;

	flag = 0;
	if (specif->width != 0)
	{
		if (ft_strchr(specif->flag, '0') && !ft_strchr(specif->flag, '-'))
		{
			if (!(spaces_zeros = f_put_zeros(specif, 1)))
				return (0);
			ft_putstr_fd(spaces_zeros, 1);
			return (0);
		}
		else
			return (f_check_flag_prc_2(specif, prc));
	}
	return (0);
}

int	f_check_flag_prc_2(t_specifier *specif, char prc)
{
	char *spaces_zeros;

	if (!(spaces_zeros = f_widht(specif, 1)))
		return (0);
	if (ft_strchr(specif->flag, '-'))
	{
		ft_putchar_fd(prc, 1);
		ft_putstr_fd(spaces_zeros, 1);
		return (1);
	}
	else
	{
		ft_putstr_fd(spaces_zeros, 1);
		return (0);
	}
}
