/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dth_i_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 07:33:42 by yhershel          #+#    #+#             */
/*   Updated: 2020/07/10 23:14:14 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		f_check_flag_d_i(t_specifier *specif, int content_d_i)
{
	char	*str;

	str = ft_itoa(content_d_i);
	if (content_d_i == 0 && specif->dot == '.' && specif->accuracy == 0)
		str = "";
	if (ft_strncmp(str, "", 1) == 0 && specif->width == 0)
	{
		free(str);
		return (2);
	}
	if (specif->accuracy > 0 && specif->width > 0)
		return (f_full_house_d_i(specif, content_d_i));
	if (specif->accuracy >= 0 && specif->accuracy > (int)ft_strlen(str))
		return (f_check_flag_d_i_2(content_d_i, specif, str));
	if (specif->width >= 0 && specif->width > (int)ft_strlen(str))
	{
		if (ft_strchr(specif->flag, '-'))
			return (f_check_flag_d_i_5(specif, str));
		else if (ft_strchr(specif->flag, '0'))
			return (f_check_flag_d_i_3(content_d_i, specif, str));
		else
			return (f_check_flag_d_i_4(specif, str));
	}
	f_free_mem(1, str);
	return (0);
}

int		f_full_house_d_i(t_specifier *specif, int content_d_i)
{
	char	*str;
	char	*new_str;
	char	*spaces;

	spaces = NULL;
	str = ft_itoa(content_d_i);
	if (specif->accuracy > (int)ft_strlen(str))
		new_str = f_full_house_d_i_2(content_d_i, specif, str);
	else
		new_str = str;
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

char	*f_full_house_d_i_2(int content_d_i, t_specifier *specif, char *str)
{
	char *new_str;

	if (content_d_i < 0)
		new_str = f_put_zeros_accurcy(specif,
			ft_strlen(ft_itoa(content_d_i * -1)));
	else
		new_str = f_put_zeros_accurcy(specif, ft_strlen(str));
	new_str = ft_strjoin(new_str, str);
	if (content_d_i < 0)
	{
		new_str[0] = '-';
		new_str = f_del_minus(new_str);
	}
	return (new_str);
}

char	*f_del_minus(char *str)
{
	int	len;

	len = ft_strlen(str);
	while (len--)
	{
		if (str[len] == '-')
		{
			str[len] = '0';
			return (str);
		}
	}
	return (str);
}
