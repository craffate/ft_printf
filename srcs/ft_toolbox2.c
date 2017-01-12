/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolbox2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:05:20 by craffate          #+#    #+#             */
/*   Updated: 2017/01/12 08:42:11 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*ft_wstrjoin_alt(const wchar_t *s1, const wchar_t *s2)
{
	unsigned int	i;
	wchar_t			*s3;

	if (!(s3 = (wchar_t *)malloc(sizeof(wchar_t) * (ft_wstrlen(s1) + ft_wstrlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (*s1)
		s3[i++] = *s1++;
	while (*s2)
		s3[i++] = *s2++;
	s3[i] = '\0';
	return (s3);
}
