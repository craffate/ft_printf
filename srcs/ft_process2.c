/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:10:05 by craffate          #+#    #+#             */
/*   Updated: 2017/01/14 11:26:47 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static wchar_t	*ft_precision_s(wchar_t *s, int *arr)
{
	wchar_t			*s2;
	unsigned int	i;

	s2 = ft_wstrnew(arr[2]);
	i = 0;
	while (i > 0)
	{
		s2[i] = s[i];
		i++;
	}
	return (s2);
}

static wchar_t	*ft_precision_int(wchar_t *s, int *arr)
{
	wchar_t			*s2;
	unsigned int	i;

	s2 = ft_wstrnew(ft_wstrlen(s) + arr[2]);
	i = 0;
	if (arr[2] != 0)
	{
		while (ft_wstrlen(s) < (size_t)arr[2]--)
			ft_wstrcat(s2, L"0");
		ft_wstrcat(s2, s);
	}
	return (s2);
}

wchar_t	*ft_precision(const char spe, wchar_t *s, int *arr)
{
	wchar_t	*s2;

	s2 = ft_wstrnew(ft_wstrlen(s) + arr[2]);
	if (spe == 'd' || spe == 'D' || spe == 'i' || spe == 'o' || spe == 'O' ||
		spe == 'x' || spe == 'X' || spe == 'u' || spe == 'U' ||
		spe == 'b' || spe == 'B')
		s2 = ft_precision_int(s, arr);
	else if (spe == 's')
		ft_precision_s(s, arr);
//	else if (spe == 'S' || (spe == 's' && arr[0] & L))
//		ft_precision_ws(s, arr);
	return (s2);
}

wchar_t	*ft_wwidth(wchar_t *s, int *arr, size_t eb)
{
	wchar_t	*s2;

	s2 = ft_wstrnew(ft_wstrlen(s) + arr[1]);
	if (!(arr[0] & ZERO))
	{
		if (!(arr[0] & MINUS))
		{
			while ((ft_wstrlen(s) + eb) < (size_t)arr[1]--)
				ft_wstrcat(s2, L" ");
			ft_wstrcat(s2, s);
		}
		else if (arr[0] & MINUS)
		{
			ft_wstrcat(s2, s);
			while ((ft_wstrlen(s) + eb) < (size_t)arr[1]--)
				ft_wstrcat(s2, L" ");
		}
	}
	else
	{
		while ((ft_wstrlen(s) + eb) < (size_t)arr[1]--)
			ft_wstrcat(s2, L"0");
		ft_wstrcat(s2, s);
	}
	return (s2);
}
