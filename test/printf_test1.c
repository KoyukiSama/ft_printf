
#include "ft_printf.h"

int main(void)
{
	int len = ft_printf("h%ss, %.i\n", " yes", 592059);
	ft_printf("%i", len);
	// line is bugged btw
}
