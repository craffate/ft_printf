/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:51:49 by craffate          #+#    #+#             */
/*   Updated: 2016/11/16 11:20:49 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	n2;

	n2 = n;
	if (n < 0)
	{
		ft_putchar('-');
		n2 = n * -1;
	}
	if (n2 >= 10)
		ft_putnbr(n2 / 10);
	ft_putchar(n2 % 10 + '0');
}
