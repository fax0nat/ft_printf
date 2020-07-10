/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dth_i_d_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 02:56:29 by yhershel          #+#    #+#             */
/*   Updated: 2020/07/10 22:51:56 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		f_check_flag_d_i_2(int content_d_i, t_specifier *specif, char *str)
{
	char	*new_str_accuracy;

	if (content_d_i < 0)
		new_str_accuracy = f_put_zeros_accurcy(specif,
			ft_strlen(ft_itoa(content_d_i * -1)));
	else
		new_str_accuracy = f_put_zeros_accurcy(specif, ft_strlen(str));
	new_str_accuracy = ft_strjoin(new_str_accuracy, str);
	if (content_d_i < 0)
	{
		new_str_accuracy[0] = '-';
		new_str_accuracy = f_del_minus(new_str_accuracy);
	}
	ft_putstr_fd(new_str_accuracy, 1);
	f_free_mem(2, new_str_accuracy, str);
	return (1);
}

int		f_check_flag_d_i_3(int content_d_i, t_specifier *specif, char *str)
{
	char *new_str_accuracy;

	new_str_accuracy = f_put_zeros(specif, ft_strlen(str));
	new_str_accuracy = ft_strjoin(new_str_accuracy, str);
	if (content_d_i < 0)
	{
		new_str_accuracy[0] = '-';
		new_str_accuracy = f_del_minus(new_str_accuracy);
	}
	ft_putstr_fd(new_str_accuracy, 1);
	f_free_mem(2, new_str_accuracy, str);
	return (1);
}

int		f_check_flag_d_i_4(t_specifier *specif, char *str)
{
	char *spaces_zeros;

	spaces_zeros = f_widht(specif, ft_strlen(str));
	ft_putstr_fd(spaces_zeros, 1);
	ft_putstr_fd(str, 1);
	f_free_mem(2, spaces_zeros, str);
	return (1);
}

int		f_check_flag_d_i_5(t_specifier *specif, char *str)
{
	char *spaces_zeros;

	spaces_zeros = f_widht(specif, ft_strlen(str));
	ft_putstr_fd(str, 1);
	ft_putstr_fd(spaces_zeros, 1);
	f_free_mem(2, spaces_zeros, str);
	return (1);
}
