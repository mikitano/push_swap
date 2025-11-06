#include "ft_printf.h"

int	ft_address_hex(void *ptr)
{
	int				count;
	unsigned long	ptr_long;

	count = 0;
	if (!ptr)
		return(ft_putstr("(nil)"));
	ptr_long = (unsigned long)ptr;
	count += ft_putstr("0x");
	count += ft_putnbr_hex(ptr_long, 'x');
	return (count);
}
