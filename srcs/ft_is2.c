/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:11:07 by craffate          #+#    #+#             */
/*   Updated: 2017/01/09 17:29:31 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdouble(const char c)
{
	if (c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g' || c == 'G'
			|| c == 'a' || c == 'A')
		return (1);
	else
		return (0);
}
