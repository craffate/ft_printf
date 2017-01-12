/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolbox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:40:04 by craffate          #+#    #+#             */
/*   Updated: 2017/01/12 09:24:29 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_extrabits(const wchar_t *s)
{
	size_t			i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] > 0x10000)
			i += 3;
		else if (s[j] > 0x800)
			i += 2;
		else if (s[j] > 0x80)
			i += 1;
		j++;
	}
	return (i);
}

static size_t	ft_getsize(unsigned long long n, unsigned int b)
{
	size_t	size;

	size = 1;
	while (n /= b)
		size += 1;
	return (size);
}

wchar_t		*ft_ullitoa_base(unsigned long long n, unsigned int b, const char spe)
{
	wchar_t	*s;
	size_t	len;

	len = ft_getsize(n, b);
	s = ft_wstrnew(len + 1);
	s[len--] = 0;
	while (n >= b)
	{
		s[len--] = ((spe > 64 && spe < 91) ? ("0123456789ABCDEF")[n % b] :
		("0123456789abcdef")[n % b]);
		n /= b;
	}
	s[len--] = ((spe > 64 && spe < 91) ? ("0123456789ABCDEF")[n % b] :
	("0123456789abcdef")[n % b]);
	return (s);
}

wchar_t		*ft_llitoa_base(long long n, unsigned int b, const char spe)
{
	wchar_t	*s;
	size_t	len;
	int		neg;

	neg = 0;
	if (n < 0)
	{
		n *= -1;
		neg = 1;
	}
	len = ft_getsize(n, b);
	len += neg == 1 ? 1 : 0;
	s = neg == 1 ? ft_wstrnew(len + 1) : ft_wstrnew(len);
	s[0] = neg == 1 ? '-' : s[0];
	s[len--] = 0;
	while (n >= b)
	{
		s[len--] = ((spe > 64 && spe < 91) ? ("0123456789ABCDEF")[n % b] :
		("0123456789abcdef")[n % b]);
		n /= b;
	}
	s[len--] = ((spe > 64 && spe < 91) ? ("0123456789ABCDEF")[n % b] :
	("0123456789abcdef")[n % b]);
	return (s);
}

wchar_t	*ft_strtowstr(const char *s)
{
	unsigned int	i;
	wchar_t			*s2;

	i = 0;
	if (!(s2 = (wchar_t *)malloc(sizeof(wchar_t) * ft_strlen(s) + 1)))
		return (NULL);
	while (*s)
		s2[i++] = *s++;
	s2[i] = '\0';
	return (s2);
}
