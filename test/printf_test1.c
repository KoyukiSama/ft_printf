
#include "ft_printf.h"

int main(void)
{
	int len;

	len = ft_printf("|%d|", 5920598);
	ft_printf("%i", len);
	// line is bugged btw
}
