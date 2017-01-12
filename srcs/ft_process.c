/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 12:30:28 by craffate          #+#    #+#             */
/*   Updated: 2017/01/11 12:13:58 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static wchar_t	*ft_plus(const wchar_t *s)
{
	wchar_t	*s2;

	s2 = ft_wstrnew(ft_wstrlen(s) + 2);
	ft_wstrcat(s2, L"+");
	ft_wstrcat(s2, s);
	return (s2);
}

static wchar_t	*ft_width(const wchar_t *s, int *arr)
{
	wchar_t	*s2;

	s2 = ft_wstrnew(ft_wstrlen(s) + arr[1] + 1);
	if (!(arr[0] & MINUS))
	{
		while (ft_wstrlen(s) < (size_t)arr[1]--)
			ft_wstrcat(s2, L" ");
		ft_wstrcat(s2, s);
	}
	else if (arr[0] & MINUS)
	{
		ft_wstrcat(s2, s);
		while (ft_wstrlen(s) < (size_t)arr[1]--)
			ft_wstrcat(s2, L" ");
	}
	return (s2);
}

static wchar_t	*ft_sharp(const wchar_t *s, char spe)
{
	wchar_t	*s2;

	s2 = ft_wstrnew(ft_wstrlen(s) + 3);
	if (spe == 'x')
		ft_wstrcat(s2, L"0x");
	else if (spe == 'X')
		ft_wstrcat(s2, L"0X");
	else if (spe == 'o' || spe == 'O')
		ft_wstrcat(s2, L"0");
	ft_wstrcat(s2, s);
	return (s2);
}

wchar_t			*ft_process(const wchar_t *s, char spe, int *arr)
{
	wchar_t	*s2;

	s2 = (wchar_t *)s;
	if (arr[0] & SHARP && (spe == 'o' || spe == 'O' || spe == 'x' || spe == 'X'))
		s2 = ft_sharp(s, spe);
	if (arr[0] & PLUS && (spe == 'u' || spe == 'd' || spe == 'i') && !(s[0] == '-' || s[0] == '+'))
		s2 = ft_plus(s2);
	if (arr[1] != -2 && ft_wstrlen(s) < (size_t)arr[1])
		s2 = ft_width(s2, arr);
	return (s2);
}