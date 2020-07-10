/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhershel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 22:12:25 by yhershel          #+#    #+#             */
/*   Updated: 2020/07/10 21:36:29 by yhershel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef	struct	s_specifier
{
	char	percent;
	char	*flag;
	int		width;
	char	dot;
	int		accuracy;
	char	type;

}				t_specifier;

int				ft_printf(const char *str, ...);
void			f_parsing(size_t len, t_specifier *specif,
					va_list argptr, const char *str);
int				f_fillint_specifier(size_t i, t_specifier *specif,
					const char *str, va_list argptr);
size_t			f_fis_widht(size_t i, const char *str,
					t_specifier *specif, va_list argptr);
size_t			f_fis_accuracy(size_t i, const char *str,
					t_specifier *specif, va_list argptr);

int				f_dth_launch(t_specifier *specif, va_list argptr);
int				f_dth_launch_2(t_specifier *specif, va_list argptr);
size_t			f_accuracy_manipul(size_t i, t_specifier *specif,
					const char *str, va_list argptr);
size_t			f_width_manipul(size_t i, t_specifier *specif,
					const char *str, va_list argptr);

int				dothething_prc(t_specifier *specif, char percent);
int				dothething_s(t_specifier *specif, char *content_s);
int				dothething_d_i(t_specifier *specif, int content_d);
int				dothething_c(t_specifier *specif, char content_c);
int				dothething_p(t_specifier *specif, void *content_p);
int				dothething_u(t_specifier *specif,
					unsigned int content_u);
int				dothething_x(t_specifier *specif,
					unsigned int content_x);

int				f_check_flag_prc(t_specifier *specif, char prc);
int				f_check_flag_prc_2(t_specifier *specif, char prc);

int				f_check_flag_c(t_specifier *specif, unsigned char ch);
int				f_check_flag_s(t_specifier *specif, char *str);
int				f_check_flag_s_2(t_specifier *specif, char *str);
int				f_full_house(t_specifier *specif, char *str);

int				f_print_pointer(t_specifier *specif, void *content_p);
int				f_print_pointer_2(t_specifier *specif, char *p_hex);
char			*f_format_pointer(char *p_hex);

int				f_check_flag_d_i(t_specifier *specif, int content_d_i);
int				f_full_house_d_i(t_specifier *specif, int content_d_i);
char			*f_full_house_d_i_2(int content_d_i,
					t_specifier *specif, char *str);
char			*f_del_minus(char *str);

int				f_check_flag_d_i_2(int content_d_i,
					t_specifier *specif, char *str);
int				f_check_flag_d_i_3(int content_d_i,
					t_specifier *specif, char *str);
int				f_check_flag_d_i_4(t_specifier *specif, char *str);
int				f_check_flag_d_i_5(t_specifier *specif, char *str);

void			f_free_mem(size_t count, ...);

int				f_check_flag_u(t_specifier *specif,
					unsigned int content_d_i);
int				f_full_house_u(t_specifier *specif,
					unsigned int content_d_i);
int				f_check_flag_u_2(t_specifier *specif, char *str,
					char *new_str_accuracy);
char			*f_full_house_u_2(t_specifier *specif, char *str);

int				f_check_flag_u_3(t_specifier *specif,
					char *new_str_accuracy, char *str);

int				f_check_flag_x(t_specifier *specif, char *content_d_i);
int				f_full_house_x(t_specifier *specif, char *content_d_i);
int				f_check_flag_x_2(t_specifier *specif, char *content_x,
					char *new_str_accuracy);

char			*f_widht(t_specifier *specif, int len);
char			*f_put_zeros(t_specifier *specif, int len);
char			*f_put_zeros_accurcy(t_specifier *specif, int len);
char			*f_put_accuracy_s(t_specifier *specif, char *str);

t_specifier		*clean_specif(t_specifier *specif);
void			f_write_else_str(t_specifier *specif);
char			f_strtochr(char *str);
char			*f_stradd(char *str, char ch);
void			f_bspaces(char *str, int count);
void			f_bzeros(char *str, int count);
int				f_countdigit(const char *dig);
char			*f_strcpy(char *dest, char *src, unsigned int size);
char			*f_into_hex(unsigned long int number, int len);
char			*f_into_hex_2(unsigned long int number,
					int len, char *hex);
char			*f_tolower_str(char *str);
char			*f_positiv_itoa(unsigned int n);

#endif
