/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dth_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 05:49:58 by yhershel          #+#    #+#             */
/*   Updated: 2020/07/10 23:06:02 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		f_check_flag_u(t_specifier *specif, unsigned int content_u)
{
	char	*str;
	char	*new_str_accuracy;

	new_str_accuracy = NULL;
	str = f_positiv_itoa(content_u);
	if (content_u == 0 && specif->dot == '.' && specif->accuracy == 0)
		str = "";
	if (ft_strncmp(str, "", 1) == 0 && specif->width == 0)
	{
		f_free_mem(1, str);
		return (2);
	}
	if (specif->accuracy > 0 && specif->width > 0)
		return (f_full_house_u(specif, content_u));
	if (specif->accuracy >= 0 && specif->accuracy > (int)ft_strlen(str))
		return (f_check_flag_u_3(specif, new_str_accuracy, str));
	if (specif->width >= 0 && specif->width > (int)ft_strlen(str))
		return (f_check_flag_u_2(specif, str, new_str_accuracy));
	f_free_mem(2, str, new_str_accuracy);
	return (0);
}

int		f_check_flag_u_2(t_specifier *specif, char *str, char *new_str_accuracy)
{
	char *spaces_zeros;

	spaces_zeros = NULL;
	if (ft_strchr(specif->flag, '-'))
	{
		spaces_zeros = f_widht(specif, ft_strlen(str));
		ft_putstr_fd(str, 1);
		ft_putstr_fd(spaces_zeros, 1);
	}
	else if (ft_strchr(specif->flag, '0'))
	{
		new_str_accuracy = f_put_zeros(specif, ft_strlen(str));
		new_str_accuracy = ft_strjoin(new_str_accuracy, str);
		ft_putstr_fd(new_str_accuracy, 1);
	}
	else
	{
		spaces_zeros = f_widht(specif, ft_strlen(str));
		ft_putstr_fd(spaces_zeros, 1);
		ft_putstr_fd(str, 1);
	}
	f_free_mem(3, spaces_zeros, new_str_accuracy, str);
	return (1);
}

int		f_full_house_u(t_specifier *specif, unsigned int content_u)
{
	char	*str;
	char	*new_str;
	char	*spaces;

	spaces = NULL;
	str = f_positiv_itoa(content_u);
	new_str = f_full_house_u_2(specif, str);
	if (specif->width > (int)ft_strlen(str))
	{
		if (ft_strchr(specif->flag, '-'))
		{
			spaces = f_widht(specif, ft_strlen(new_str));
			new_str = ft_strjoin(new_str, spaces);
		}
		else
		{
			spaces = f_widht(specif, ft_strlen(new_str));
			new_str = ft_strjoin(spaces, new_str);
		}
	}
	ft_putstr_fd(new_str, 1);
	f_free_mem(3, str, new_str, spaces);
	return (1);
}

char	*f_full_house_u_2(t_specifier *specif, char *str)
{
	char *new_str;

	if (specif->accuracy > (int)ft_strlen(str))
	{
		new_str = f_put_zeros_accurcy(specif, ft_strlen(str));
		new_str = ft_strjoin(new_str, str);
	}
	else
		new_str = str;
	return (new_str);
}
