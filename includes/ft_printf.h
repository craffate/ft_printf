/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 09:30:15 by craffate          #+#    #+#             */
/*   Updated: 2017/01/12 08:41:51 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <locale.h>

# define MAXCHARS (65536)
# define MAXARGCHARS (1024)
# define H (1 << 0)
# define HH (1 << 1)
# define L (1 << 2)
# define LL (1 << 3)
# define J (1 << 4)
# define Z (1 << 5)
# define SHARP (1 << 6)
# define ZERO (1 << 7)
# define MINUS (1 << 8)
# define PLUS (1 << 9)
# define SPACE (1 << 10)

int			ft_printf(const char *format, ...);
const char	*ft_parse(int *arr, const char *format, va_list ap);
int			ft_isspecifier(const char c);
int			ft_isflag(const char c);
int			ft_islength(const char c);
int			ft_savefl(unsigned short i, const char c);
int			ft_savele(unsigned short i, const char *s);
int			ft_isint(const char c);
int			ft_isuint(const char c);
int			ft_isdouble(const char c);
wchar_t		*ft_preprocess(const char spe, va_list ap, int *arr, size_t *i);
wchar_t		*ft_process(const wchar_t *s, char spe, int *arr);
wchar_t		*ft_llitoa_base(long long n, unsigned int b, const char spe);
wchar_t		*ft_ullitoa_base(unsigned long long n, unsigned int b, const char spe);
size_t		ft_extrabits(const wchar_t *s);
wchar_t		*ft_strtowstr(const char *s);
wchar_t		*ft_wstrjoin_alt(const wchar_t *s1, const wchar_t *s2);

#endif
