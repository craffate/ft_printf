/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:57:01 by craffate          #+#    #+#             */
/*   Updated: 2017/01/10 09:21:47 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_getsize(int n, int b)
{
	size_t	size;

	size = 1;
	while (n /= b)
		size += 1;
	return (size);
}

static char		*ft_llitoa_base(long long n, int b, const char spe)
{
	char	*s;
	size_t	len;

	len = ft_getsize(n, b);
	if (!(s = (char *)malloc(sizeof(wchar_t) * (len + 1))))
		return (0);
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

static wchar_t	*ft_strtowstr(const char *s)
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

wchar_t			*ft_preprocess(const char spe, va_list ap)
{
	char	*tmp;
	wchar_t	*wtmp;

	wtmp = NULL;
	if (spe == 'd' || spe == 'i')
		tmp = ft_llitoa_base((long long)va_arg(ap, int), 10, spe);
	if (spe == 'u')
		tmp = ft_llitoa_base((long long)va_arg(ap, unsigned int), 10, spe);
	if (spe == 'o' || spe == 'O')
		tmp = ft_llitoa_base((long long)va_arg(ap, unsigned int), 8, spe);
	if (spe == 'x' || spe == 'X')
		tmp = ft_llitoa_base((long long)va_arg(ap, unsigned int), 16, spe);
	if (spe == 's')
		tmp = va_arg(ap, char *);
	if (spe == 'S')
		wtmp = va_arg(ap, wchar_t *);
	wtmp = wtmp == NULL ? ft_strtowstr(tmp) : wtmp;
	return (wtmp);
}
