
#include "ft_printf.h"
#define PPL "\e[95m"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	//ft_printf("len: %i ✅\n\n", len); // if you want to check length
	ft_printf(PPL"<3-----[TESTS 1]: %%c testing-----<3\n"RESET);
	ft_printf("|%c|\n", 'a');
	ft_printf("|%.5c|\n", 'a');
	ft_printf("|%05c|\n", 'a');
	ft_printf("|%5c|\n", 'a');
	ft_printf("|%-5c|\n", 'a');

	ft_printf(PPL"<3-----[TESTS 2]: %%s testing-----<3\n"RESET);
	ft_printf("|%s|\n", "hello");
	ft_printf("|%.6s|\n", "hello");
	ft_printf("|%.3s|\n", "hello");
	ft_printf("|%.0s|\n", "hello");
	ft_printf("|%05s|\n", "hello");
	ft_printf("|%6s|\n", "hello");
	ft_printf("|%-6s|\n", "hello");
	ft_printf("|%6.4s|\n", "hello");
	ft_printf("|%-6.4s|\n", "hello");
	ft_printf("|%6.0s|\n", "hello");
	ft_printf("|%-6.0s|\n", "hello");
	char *hello = 0;
	ft_printf("|%s|", hello);
	ft_printf("|%-5.0s|\n", hello);
	printf("|%-5.0s|\n", hello);
	ft_printf("|%.7s|\n", hello);
	printf("|%.7s|\n", hello);

	ft_printf(PPL"<3-----[TESTS 3]: %%d/i-----<3\n"RESET);
	ft_printf("|%d|\n", 520);
	ft_printf("|%5d|\n", 520);
	ft_printf("|%-5d|\n", 520);
	ft_printf("|%d|\n", -520);
	ft_printf("|%5d|\n", -520);
	ft_printf("|%-5d|\n", -520);
	ft_printf("|%.5d|\n", 520);
	ft_printf("|%6.5d|\n", 520);
	ft_printf("|%-6.5d|\n", 520);
	ft_printf("|%.5d|\n", -520);
	ft_printf("|%7.5d|\n", -520);
	ft_printf("|%-7.5d|\n", -520);
	ft_printf("|%05d|\n", 520);
	ft_printf("|%05d|\n", -520);
	ft_printf("|%d|\n", INT_MIN);
	printf("|%d|\n", INT_MIN);
	ft_printf("|%-14.12d|\n", INT_MIN);
	printf("|%-14.12d|\n", INT_MIN);

	ft_printf(PPL"<3-----[TESTS 4]: %%p-----<3\n"RESET);
	char *phello = 0;
	char pihello[5] = {0};
	ft_printf("|%p|\n", phello);
	ft_printf("|%p|\n", pihello);
	ft_printf("|%05p|\n", pihello);
	//printf("|%05p|\n", pihello);
	ft_printf("|%.5p|\n", pihello);
	//printf("|%.5p|\n", pihello);
	ft_printf("|%15p|\n", pihello);
	//printf("|%15p|\n", pihello);
	ft_printf("|%-15p|\n", pihello);
	//printf("|%-15p|\n", pihello);
	
	ft_printf(PPL"<3-----[TESTS 5]: %%u-----<3\n"RESET);
	ft_printf("|%u|\n", 400);
	ft_printf("|%05u|\n", 400);
	ft_printf("|%.5u|\n", 400);
	ft_printf("|%5u|\n", 400);
	ft_printf("|%-5u|\n", 400);
	ft_printf("|%u|\n", -400);
	ft_printf("|%015u|\n", -400);
	ft_printf("|%.15u|\n", -400);
	ft_printf("|%15u|\n", -400);
	ft_printf("|%-15u|\n", -400);
	ft_printf("|%12.11u|\n", -400);
	ft_printf("|%-12.11u|\n", -400);
	
	ft_printf(PPL"<3-----[TESTS 6]: %%x-----<3\n"RESET);
	ft_printf("|%x|\n", 255);
	ft_printf("|%05x|\n", 255);
	ft_printf("|%.5x|\n", 255);
	ft_printf("|%5x|\n", 255);
	ft_printf("|%-5x|\n", 255);
	ft_printf("|%x|\n", -255);
	ft_printf("|%015x|\n", -255);
	ft_printf("|%.15x|\n", -255);
	ft_printf("|%15x|\n", -255);
	ft_printf("|%-15x|\n", -255);
	ft_printf("|%12.11x|\n", -255);
	ft_printf("|%-12.11x|\n", -255);

	ft_printf(PPL"<3-----[TESTS 7]: %%X-----<3\n"RESET);
	ft_printf("|%X|\n", 255);
	ft_printf("|%05X|\n", 255);
	ft_printf("|%.5X|\n", 255);
	ft_printf("|%5X|\n", 255);
	ft_printf("|%-5X|\n", 255);
	ft_printf("|%X|\n", -255);
	ft_printf("|%015X|\n", -255);
	ft_printf("|%.15X|\n", -255);
	ft_printf("|%15X|\n", -255);
	ft_printf("|%-15X|\n", -255);
	ft_printf("|%12.11X|\n", -255);
	ft_printf("|%-12.11X|\n", -255);
}