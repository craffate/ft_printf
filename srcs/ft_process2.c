/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:10:05 by craffate          #+#    #+#             */
/*   Updated: 2017/01/12 16:30:18 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*ft_wwidth(const wchar_t *s, int *arr, size_t eb)
{
	wchar_t	*s2;

	s2 = ft_wstrnew(ft_wstrlen(s) + arr[1] + 1);
	ft_putchar('a');
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
