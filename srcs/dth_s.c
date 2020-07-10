/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dth_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:21:31 by yhershel          #+#    #+#             */
/*   Updated: 2020/07/10 22:30:57 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	f_check_flag_c(t_specifier *specif, unsigned char ch)
{
	char	*spaces;

	spaces = NULL;
	if (specif->width != 0)
	{
		spaces = f_widht(specif, 1);
		if (ft_strchr(specif->flag, '-'))
		{
			ft_putchar_fd(ch, 1);
			ft_putstr_fd(spaces, 1);
			free(spaces);
			return (1);
		}
		else
			ft_putstr_fd(spaces, 1);
	}
	f_free_mem(1, spaces);
	return (0);
}

int	f_check_flag_s(t_specifier *specif, char *str)
{
	char *new_str_accuracy;

	new_str_accuracy = NULL;
	if (specif->dot == '.' && specif->width > 0)
		return (f_full_house(specif, str));
	if (specif->accuracy > 0)
	{
		new_str_accuracy = f_put_accuracy_s(specif, str);
		ft_putstr_fd(new_str_accuracy, 1);
		f_free_mem(1, new_str_accuracy);
		return (1);
	}
	else if (specif->dot == '.' && specif->accuracy == 0)
	{
		ft_putstr_fd("", 1);
		f_free_mem(1, new_str_accuracy);
		return (1);
	}
	if (specif->width != 0)
		return (f_check_flag_s_2(specif, str));
	f_free_mem(1, new_str_accuracy);
	return (0);
}

int	f_check_flag_s_2(t_specifier *specif, char *str)
{
	char *spaces;

	spaces = f_widht(specif, ft_strlen(str));
	if (ft_strchr(specif->flag, '-'))
	{
		ft_putstr_fd(str, 1);
		ft_putstr_fd(spaces, 1);
		f_free_mem(1, spaces);
		return (1);
	}
	else
		ft_putstr_fd(spaces, 1);
	f_free_mem(1, spaces);
	return (0);
}

int	f_full_house(t_specifier *specif, char *str)
{
	char	*spaces;
	char	*new_str_accuracy;

	new_str_accuracy = f_put_accuracy_s(specif, str);
	spaces = f_widht(specif, ft_strlen(new_str_accuracy));
	if (ft_strchr(specif->flag, '-'))
	{
		ft_putstr_fd(new_str_accuracy, 1);
		ft_putstr_fd(spaces, 1);
	}
	else
	{
		ft_putstr_fd(spaces, 1);
		ft_putstr_fd(new_str_accuracy, 1);
	}
	f_free_mem(2, spaces, new_str_accuracy);
	return (1);
}
