/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:57:01 by craffate          #+#    #+#             */
/*   Updated: 2017/01/12 13:54:03 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static wchar_t	*ft_preprocesspercent(void)
{
	wchar_t	*s;

	s = ft_wstrnew(1);
	ft_wstrcat(s, L"%");
	return (s);
}

static wchar_t	*ft_preprocessuint(const char spe, va_list ap, int *arr)
{
	wchar_t	*s;

	if (arr[0] & HH || arr[0] & H)
		s = ft_llitoa_base((long long)va_arg(ap, int), 10, spe);
	else if ((arr[0] & L && spe == 'u') || spe == 'U')
		s = ft_llitoa_base((long long)va_arg(ap, unsigned long int), 10, spe);
	else if (arr[0] & L && (spe == 'x' || spe == 'X'))
		s = ft_llitoa_base((long long)va_arg(ap, unsigned long int), 16, spe);
	else if ((arr[0] & L && spe == 'o') || spe == 'O')
		s = ft_llitoa_base((long long)va_arg(ap, unsigned long int), 8, spe);
	else if (arr[0] & LL)
		s = ft_llitoa_base((long long)va_arg(ap, unsigned long long int),
			10, spe);
	else if (arr[0] & J)
		s = ft_llitoa_base((long long)va_arg(ap, uintmax_t), 10, spe);
	else if (arr[0] & Z)
		s = ft_llitoa_base((long long)va_arg(ap, size_t), 10, spe);
	else if (spe == 'o')
		s = ft_llitoa_base((long long)va_arg(ap, unsigned int), 8, spe);
	else if (spe == 'X' || spe == 'x')
		s = ft_llitoa_base((long long)va_arg(ap, unsigned int), 16, spe);
	else if (spe == 'b' || spe == 'B')
		s = ft_llitoa_base((long long)va_arg(ap, unsigned int), 2, spe);
	else
		s = ft_llitoa_base((long long)va_arg(ap, unsigned int), 10, spe);
	return (s);
}

static wchar_t	*ft_preprocessint(const char spe, va_list ap, int *arr)
{
	wchar_t	*s;

	if (arr[0] & HH || arr[0] & H)
		s = ft_llitoa_base((long long)va_arg(ap, int), 10, spe);
	else if ((arr[0] & L && spe == 'd') || spe == 'D')
		s = ft_llitoa_base((long long)va_arg(ap, long int), 10, spe);
	else if (arr[0] & LL)
		s = ft_llitoa_base((long long)va_arg(ap, long long int), 10, spe);
	else if (arr[0] & J)
		s = ft_llitoa_base((long long)va_arg(ap, intmax_t), 10, spe);
	else if (arr[0] & Z)
		s = ft_llitoa_base((long long)va_arg(ap, size_t), 10, spe);
	else if (spe == 'p' || spe == 'P')
		s = ft_llitoa_base((long long)va_arg(ap, void *), 16, spe);
	else
		s = ft_llitoa_base((long long)va_arg(ap, int), 10, spe);
	return (s);
}

wchar_t			*ft_preprocessstr(const char spe, va_list ap, int *arr)
{
	char	*s;
	wchar_t	*ws;

	ws = NULL;
	if (spe == 's' && !(arr[0] & L))
	{
		s = va_arg(ap, char *);
		if (!(s == NULL))
			ws = ft_strtowstr(s);
		else
		{
			ws = ft_wstrnew(6);
			ft_wstrcat(ws, L"(null)");
		}
	}
	else if (spe == 'S' || (spe == 's' && arr[0] & L))
	{
		ws = va_arg(ap, wchar_t *);
		if (ws == NULL)
		{
			ws = ft_wstrnew(6);
			ft_wstrcat(ws, L"(null)");
		}
	}
	return (ws);
}

wchar_t			*ft_preprocess(const char spe, va_list ap, int *arr, size_t *i)
{
	char	*tmp;
	wchar_t	*wtmp;

	tmp = NULL;
	if (spe == 'd' || spe == 'i' || spe == 'D' || spe == 'p' || spe == 'P')
		wtmp = ft_preprocessint(spe, ap, arr);
	if (spe == 'u' || spe == 'o' || spe == 'x' || spe == 'O'
		|| spe == 'X' || spe == 'b' || spe == 'B')
		wtmp = ft_preprocessuint(spe, ap, arr);
	if (spe == 'c' && !(arr[0] & L))
	{
		tmp = ft_strnew(1);
		*tmp = va_arg(ap, int);
		wtmp = ft_strtowstr(tmp);
	}
	if (spe == 'C' || (spe == 'c' && arr[0] & L))
	{
		wtmp = ft_wstrnew(1);
		*wtmp = va_arg(ap, wint_t);
	}
	if (spe == 'S' || spe == 's')
		wtmp = ft_preprocessstr(spe, ap, arr);
	if (spe == '%')
		wtmp = ft_preprocesspercent();
	*i += ft_extrabits(wtmp);
	return (wtmp);
}
