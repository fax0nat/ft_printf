/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dth_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 06:36:50 by yhershel          #+#    #+#             */
/*   Updated: 2020/07/10 22:02:42 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	f_check_flag_x(t_specifier *specif, char *content_x)
{
	char	*new_str_accuracy;

	new_str_accuracy = NULL;
	if (ft_strncmp(content_x, "0", 1) == 0
			&& specif->dot == '.' && specif->accuracy == 0)
		content_x = "";
	if (ft_strncmp(content_x, "", 1) == 0 && specif->width == 0)
	{
		f_free_mem(1, new_str_accuracy);
		return (2);
	}
	if (specif->accuracy > 0 && specif->width > 0)
		return (f_full_house_x(specif, content_x));
	if (specif->accuracy >= 0 && specif->accuracy > (int)ft_strlen(content_x))
	{
		new_str_accuracy = f_put_zeros_accurcy(specif, ft_strlen(content_x));
		new_str_accuracy = ft_strjoin(new_str_accuracy, content_x);
		ft_putstr_fd(new_str_accuracy, 1);
		f_free_mem(1, new_str_accuracy);
		return (1);
	}
	if (specif->width >= 0 && specif->width > (int)ft_strlen(content_x))
		return (f_check_flag_x_2(specif, content_x, new_str_accuracy));
	f_free_mem(1, new_str_accuracy);
	return (0);
}

int	f_check_flag_x_2(t_specifier *specif, char *content_x,
		char *new_str_accuracy)
{
	char	*spaces_zeros;

	spaces_zeros = NULL;
	if (ft_strchr(specif->flag, '-'))
	{
		spaces_zeros = f_widht(specif, ft_strlen(content_x));
		ft_putstr_fd(content_x, 1);
		ft_putstr_fd(spaces_zeros, 1);
	}
	else if (ft_strchr(specif->flag, '0'))
	{
		new_str_accuracy = f_put_zeros(specif, ft_strlen(content_x));
		new_str_accuracy = ft_strjoin(new_str_accuracy, content_x);
		ft_putstr_fd(new_str_accuracy, 1);
	}
	else
	{
		spaces_zeros = f_widht(specif, ft_strlen(content_x));
		ft_putstr_fd(spaces_zeros, 1);
		ft_putstr_fd(content_x, 1);
	}
	f_free_mem(3, spaces_zeros, new_str_accuracy);
	return (1);
}

int	f_full_house_x(t_specifier *specif, char *content_x)
{
	char	*new_str;
	char	*spaces;

	spaces = NULL;
	if (specif->accuracy > (int)ft_strlen(content_x))
	{
		new_str = f_put_zeros_accurcy(specif, ft_strlen(content_x));
		new_str = ft_strjoin(new_str, content_x);
	}
	else
		new_str = content_x;
	if (specif->width > (int)ft_strlen(content_x))
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
	f_free_mem(2, new_str, spaces);
	return (1);
}
