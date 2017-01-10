/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:56:49 by craffate          #+#    #+#             */
/*   Updated: 2017/01/10 10:22:00 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*ft_formatcat(wchar_t *s1, const char *format)
{
	size_t	i;
	size_t	j;
	wchar_t	*tmp;

	i = 0;
	j = 0;
	while (format[j] && format[j] != '%')
		j++;
	if (!(tmp = (wchar_t *)malloc(sizeof(wchar_t) * (j + 1))))
				return (NULL);
	while (j > 0)
	{
		tmp[i++] = *format++;
		j--;
	}
	tmp[i] = '\0';
	ft_wstrcat(s1, tmp);
	return (format);
}

int					ft_printf(const char *format, ...)
{
	va_list	ap;
	int		arr[3];
	wchar_t	*s;
	wchar_t	*tmp;

	setlocale(LC_CTYPE, "");
	tmp = NULL;
	if (!(s = (wchar_t *)malloc(sizeof(wchar_t) * INT_MAX)))
		return (0);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format = ft_parse(arr, format, ap);
			tmp = ft_preprocess(*format, ap);
			ft_wstrcat(s, tmp);
			format++;
		}
		if (*format != '%')
			format = ft_formatcat(s, format);
	}
	ft_putwstr(s);
	va_end(ap);
	ft_putchar('\n');
	ft_putstr("Final size: ");
	ft_putnbr(ft_wstrlen(s));
	return (ft_wstrlen(s));
}
