/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 22:15:49 by yhershel          #+#    #+#             */
/*   Updated: 2020/07/10 23:00:58 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_printf(const char *str, ...)
{
	va_list		argpt;
	t_specifier	specif;
	size_t		len;

	va_start(argpt, str);
	len = ft_strlen(str);
	clean_specif(&specif);
	f_parsing(len, &specif, argpt, str);
	va_end(argpt);
	return (0);
}

void	f_parsing(size_t len, t_specifier *specif,
			va_list argptr, const char *str)
{
	size_t	i;
	int		flag;

	i = 0;
	while (i < len)
	{
		flag = 0;
		clean_specif(specif);
		if (str[i] == '%')
		{
			specif->percent = '%';
			++i;
			i = f_fillint_specifier(i, specif, str, argptr);
			flag = f_dth_launch(specif, argptr);
		}
		if (i < len && flag == 0)
		{
			ft_putchar_fd(str[i], 1);
			++i;
		}
	}
}

int		f_fillint_specifier(size_t i, t_specifier *specif,
			const char *str, va_list argptr)
{
	char	*types;
	char	*flags;

	types = "cspdiuxX%";
	flags = "-0";
	while (ft_strchr(flags, str[i]))
		specif->flag = f_stradd(specif->flag, str[i++]);
	i = f_fis_widht(i, str, specif, argptr);
	if (specif->percent == '%')
		i = f_fis_accuracy(i, str, specif, argptr);
	if (ft_strchr(types, str[i]) && specif->percent == '%')
		specif->type = str[i++];
	else
	{
		f_write_else_str(specif);
		return (i);
	}
	return (i);
}

size_t	f_fis_widht(size_t i, const char *str,
			t_specifier *specif, va_list argptr)
{
	char *types;

	types = "cspdiuxX%";
	if (ft_isdigit(str[i]) || str[i] == '*')
		i = f_width_manipul(i, specif, str, argptr);
	else if (str[i] != '.' && !ft_strchr(types, str[i]))
		f_write_else_str(specif);
	return (i);
}

size_t	f_fis_accuracy(size_t i, const char *str,
			t_specifier *specif, va_list argptr)
{
	char *types;

	types = "cspdiuxX%";
	if (str[i] == '.')
	{
		specif->dot = str[i++];
		if (!(str[i] >= '0' && str[i] <= '9')
			&& str[i] != '*' && !ft_strchr(types, str[i]))
		{
			f_write_else_str(specif);
			return (i);
		}
		else
			i = f_accuracy_manipul(i, specif, str, argptr);
	}
	return (i);
}
