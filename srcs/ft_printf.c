/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:56:49 by craffate          #+#    #+#             */
/*   Updated: 2017/01/12 17:14:11 by craffate         ###   ########.fr       */
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
	while (format[j] && format[j] != '%' && format[j] != '{')
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
	free(tmp);
	return (format);
}

int					ft_printf(const char *format, ...)
{
	va_list	ap;
	int		arr[3];
	wchar_t	*s;
	wchar_t	*tmp;
	size_t	i;

	tmp = ft_wstrnew(MAXARGCHARS);
	i = 0;
	s = ft_wstrnew(0);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			ft_putchar('a');
			format = ft_parse(arr, format, ap);
			ft_putchar('a');
			tmp = ft_preprocess(*format, ap, arr, &i);
			ft_putchar('a');
			if ((arr[0] & MINUS || arr[0] & PLUS || arr[0] & SPACE
			|| arr[0] & SHARP || arr[0] & ZERO) || arr[1] != -2 ||
			arr[2] != -2 || *format == 'p' || *format == 'P')
				tmp = ft_process(tmp, *format, arr);
			s = ft_wstrjoin_alt(s, tmp);
			format++;
		}
	//	if (*format == '{')
	//		format = ft_colors(format, &s);
		if (*format != '%' && *format != '{')
			format = ft_formatcat(s, format);
	}
	ft_putwstr(s);
	va_end(ap);
	return (ft_wstrlen(s) + i);
}
