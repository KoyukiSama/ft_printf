
#include "ft_printf.h"
#define PPL "\e[95m"

int main(void)
{
	int len;

	// char testing
	ft_printf(PPL"<3-----[TESTS 1]: char testing-----<3\n"RESET, 'c');
	len = ft_printf("|%c|\n", 'a');
	ft_printf("len: %i ✅\n", len);
	len = ft_printf("|%05c|\n", 'a');
	ft_printf("len: %i ✅\n\n", len);

	ft_printf(PPL"<3-----[TESTS 2]: char * testing-----<3\n"RESET, 'c');
	len = ft_printf("|%s|\n", "hello");
	ft_printf("len: %i ✅\n\n", len);
	
	ft_printf(PPL"<3-----[TESTS 3]: digit testing-----<3\n"RESET, 'c');
	len = ft_printf("|%d|\n", -520);
	ft_printf("len: %i ✅\n\n", len);
	// line is bugged btw
}
