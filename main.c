#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	setlocale(LC_CTYPE, "");

	ft_printf("%12.6d\n", 42);
	printf("%12.6d", 42);
	/* ft_printf("{%s}", "lol");
	ft_putchar('\n');
	ft_printf("{red}{{{green} %-10ls}}", L"千本桜");
	ft_putchar('\n');
	ft_printf("{magenta}%%%%lolxd      %%%%%%{cyan} %*s %%{eoc}%%", 42, "ptdr");
	ft_putchar('\n');
	ft_printf("{green}%#x{magenta}%12ls{eoc}", 42, L"千本桜");
	ft_putchar('\n');
	ft_printf("{cyan}%-*.S{eoc}", 14, L"千本桜");
	ft_putchar('\n');
	ft_printf("{green}{red}%22.23s{magenta}%*.ls{eoc}", L"千本桜", 12, NULL);
	ft_putchar('\n');
	ft_printf("{blue}lolxd %s  %%%%           {yellow}%#b%d%d{eoc}", "aime des airs", 42, 42, 42);
	ft_putchar('\n');
	ft_printf("{green}%dbbb{white}%#bbbb{cyan}%#xbbb{magenta}%dbbb{blue}%#Bbbb{yellow}%#bbbb{red}%#Xbbb{eoc}%+d", "千本桜", 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42);
	ft_putchar('\n');
	ft_printf("{blue}%%%%%%%%%%%%%%%%{white}%ls{red}%%%%%%%%%%%%{eoc}", L"千本桜");
	ft_putchar('\n');
	ft_printf("{cyan}[1]{yellow}\t1337 {blue}%s%*ls\t{red}./a.out{eoc}", "segmentation", 6, L"fault");
	ft_putchar('\n'); */
	return (0);
}
