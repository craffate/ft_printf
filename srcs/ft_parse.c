/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 09:33:02 by craffate          #+#    #+#             */
/*   Updated: 2017/01/14 15:56:26 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_memfinder(const char *format)
{
	size_t	i;

	i = 0;
	if (*format == '*')
		return (i);
	while (ft_isdigit(format[i]) && format[i] != '.' &&
			!(ft_isspecifier(format[i])))
		i += 1;
	return (i);
}

static const char	*ft_parsewi(int *arr, const char *format, va_list ap)
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	tmp = ft_strnew(ft_memfinder(format));
	if (*format == '*')
	{
		arr[1] = va_arg(ap, int);
		free(tmp);
		return (format + 1);
	}
	while (ft_isdigit(*format))
		tmp[i++] = *format++;
	tmp[i] = '\0';
	arr[1] = *tmp ? ft_atoi(tmp) : arr[1];
	free(tmp);
	return (format);
}

static const char	*ft_parsepr(int *arr, const char *format, va_list ap)
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	tmp = ft_strnew(ft_memfinder(format));
	if (ft_isspecifier(*format) || ft_islength(*format))
	{
		arr[2] = 0;
		free(tmp);
		return (format + 1);
	}
	else if (*format == '*')
	{
		arr[2] = va_arg(ap, int);
		free(tmp);
		return (format + 1);
	}
	while (ft_isdigit(*format))
		tmp[i++] = *format++;
	tmp[i] = '\0';
	arr[2] = *tmp ? ft_atoi(tmp) : 0;
	free(tmp);
	return (format);
}

static int			ft_parseflle(const char *format, unsigned int *i)
{
	if (ft_isflag(*format))
	{
		*i |= ft_savefl(*i, *format);
		return (1);
	}
	else if (ft_islength(*format))
	{
		*i |= ft_savele(*i, format);
		return (1);
	}
	return (0);
}

const char			*ft_parse(int *arr, const char *format, va_list ap)
{
	unsigned int	i;

	i = 0;
	arr[1] = -2;
	arr[2] = -2;
	if (*++format == '%')
		return (format);
	while (!ft_isspecifier(*format))
		if ((*format == 'h' || *format == 'l') && (i & LL || i & HH))
			format++;
		else if (ft_isflag(*format) || ft_islength(*format))
		{
			ft_parseflle(format, &i);
			format++;
		}
		else if ((*format == '.' && (ft_isdigit(*(format + 1)) ||
				*(format + 1) == '*')) && arr[2] == -2)
			format = ft_parsepr(arr, format + 1, ap);
		else if ((ft_isdigit(*format) || *format == '*') && arr[1] == -2)
			format = ft_parsewi(arr, format, ap);
		else
			format++;
	arr[0] = i;
	return (format);
}
