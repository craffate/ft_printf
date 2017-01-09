/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:57:01 by craffate          #+#    #+#             */
/*   Updated: 2017/01/09 17:32:55 by craffate         ###   ########.fr       */
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

static char	*ft_llitoa_base(long long n, int b, const char spe)
{
	char	*s;
	size_t	len;

	len = ft_getsize(n, b);
	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
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

char	*ft_preprocess(const char spe, va_list ap)
{
	char	*tmp;

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
	return (tmp);
}
