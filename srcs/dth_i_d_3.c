/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dth_i_d_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 21:05:31 by yhershel          #+#    #+#             */
/*   Updated: 2020/07/10 22:17:39 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	f_free_mem(size_t count, ...)
{
	va_list	agrs;

	va_start(agrs, count);
	while (count--)
		free(va_arg(agrs, char *));
	va_end(agrs);
}
