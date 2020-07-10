/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 22:33:55 by yhershel          #+#    #+#             */
/*   Updated: 2020/07/10 23:02:49 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

size_t	f_width_manipul(size_t i, t_specifier *specif,
			const char *str, va_list argptr)
{
	int width;

	width = 0;
	if (str[i] == '*')
	{
		width = va_arg(argptr, int);
		if (width < 0)
		{
			specif->flag = f_stradd(specif->flag, '-');
			width *= -1;
		}
		specif->width = width;
		i += 1;
	}
	else
	{
		width = ft_atoi(&str[i]);
		i += f_countdigit(&str[i]);
		specif->width = width;
	}
	return (i);
}

size_t	f_accuracy_manipul(size_t i, t_specifier *specif,
			const char *str, va_list argptr)
{
	int accuracy;

	accuracy = 0;
	if (str[i] == '*')
	{
		accuracy = va_arg(argptr, int);
		specif->accuracy = accuracy;
		i += 1;
	}
	else
	{
		accuracy = ft_atoi(&str[i]);
		i += f_countdigit(&str[i]);
		specif->accuracy = accuracy;
	}
	return (i);
}

int		f_dth_launch(t_specifier *specif, va_list argptr)
{
	int check;

	check = 0;
	if (specif->type == '%')
	{
		dothething_prc(specif, '%');
		return (1);
	}
	else if (specif->type == 'c')
	{
		dothething_c(specif, va_arg(argptr, int));
		return (1);
	}
	else if (specif->type == 's')
	{
		dothething_s(specif, va_arg(argptr, char*));
		return (1);
	}
	else
		check = f_dth_launch_2(specif, argptr);
	return (check);
}

int		f_dth_launch_2(t_specifier *specif, va_list argptr)
{
	if (specif->type == 'p')
	{
		dothething_p(specif, va_arg(argptr, void*));
		return (1);
	}
	else if (specif->type == 'd' || specif->type == 'i')
	{
		dothething_d_i(specif, va_arg(argptr, int));
		return (1);
	}
	else if (specif->type == 'u')
	{
		dothething_u(specif, va_arg(argptr, unsigned int));
		return (1);
	}
	else if (specif->type == 'x' || specif->type == 'X')
	{
		dothething_x(specif, va_arg(argptr, unsigned int));
		return (1);
	}
	return (0);
}
