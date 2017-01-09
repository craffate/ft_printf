/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:56:49 by craffate          #+#    #+#             */
/*   Updated: 2017/01/09 17:35:03 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		arr[3];
	char	*s;
	char	*tmp;

	s = ft_strnew(1024);
	tmp = NULL;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format = ft_parse(arr, format, ap);
			tmp = ft_preprocess(*format, ap);
		}
		while (*format && *format != '%')
		{
			ft_strncat(s, format, 1);
			format++;
		}
		format++;
	}
	va_end(ap);
	return (ft_strlen(s));
}
