/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:47:52 by craffate          #+#    #+#             */
/*   Updated: 2017/01/13 10:29:01 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_wstrncmp_alt(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*s1 && *s1 == *s2 && i < n)
	{
		s1++;
		s2++;
		i++;
		if (i == n)
			return (1);
	}
	return (0);

}

const char	*ft_colors(const char *format, wchar_t **s)
{
	if (ft_wstrncmp_alt(format, "{eoc}", 5))
	{
		*s = ft_wstrjoin(*s, EOC);
		return (format + 5);
	}
	if (ft_wstrncmp_alt(format, "{red}", 5))
	{
		*s = ft_wstrjoin(*s, RED);
		return (format + 5);
	}
	if (ft_wstrncmp_alt(format, "{green}", 7))
	{
		*s = ft_wstrjoin(*s, GREEN);
		return (format + 7);
	}
	if (ft_wstrncmp_alt(format, "{yellow}", 8))
	{
		*s = ft_wstrjoin(*s, YELLOW);
		return (format + 8);
	}
	if (ft_wstrncmp_alt(format, "{blue}", 6))
	{
		*s = ft_wstrjoin(*s, BLUE);
		return (format + 6);
	}
	if (ft_wstrncmp_alt(format, "{magenta}", 9))
	{
		*s = ft_wstrjoin(*s, MAGENTA);
		return (format + 9);
	}
	if (ft_wstrncmp_alt(format, "{cyan}", 6))
	{
		*s = ft_wstrjoin(*s, CYAN);
		return (format + 6);
	}
	if (ft_wstrncmp_alt(format, "{white}", 7))
	{
		*s = ft_wstrjoin(*s, WHITE);
		return (format + 7);
	}
	return (format);
}
