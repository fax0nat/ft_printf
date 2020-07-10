/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dothething.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 23:53:24 by yhershel          #+#    #+#             */
/*   Updated: 2020/07/10 19:01:46 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	dothething_prc(t_specifier *specif, char percent)
{
	int flag;

	flag = f_check_flag_prc(specif, percent);
	if (flag == 0)
		ft_putchar_fd('%', 1);
	return (0);
}

int	dothething_c(t_specifier *specif, char content_c)
{
	int flag;

	flag = f_check_flag_c(specif, content_c);
	if (flag == 0)
		ft_putchar_fd(content_c, 1);
	return (0);
}

int	dothething_s(t_specifier *specif, char *content_s)
{
	int flag;

	if (specif->width < 0)
		specif->width = 0;
	if (content_s == NULL)
		content_s = "(null)";
	flag = f_check_flag_s(specif, content_s);
	if (flag == 0)
		ft_putstr_fd(content_s, 1);
	return (0);
}

int	dothething_p(t_specifier *specif, void *content_p)
{
	f_print_pointer(specif, content_p);
	return (0);
}
