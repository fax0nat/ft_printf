/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dth_u_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 21:33:18 by yhershel          #+#    #+#             */
/*   Updated: 2020/07/10 23:08:41 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	f_check_flag_u_3(t_specifier *specif, char *new_str_accuracy, char *str)
{
	new_str_accuracy = f_put_zeros_accurcy(specif, ft_strlen(str));
	new_str_accuracy = ft_strjoin(new_str_accuracy, str);
	ft_putstr_fd(new_str_accuracy, 1);
	f_free_mem(2, new_str_accuracy, str);
	return (1);
}
