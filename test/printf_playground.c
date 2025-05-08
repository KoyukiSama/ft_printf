
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("%01d\n", 42);
	printf("%.1d\n\n", 42);

	printf("%02d\n", 42);
	printf("%.2d\n\n", 42);

	printf("%03d\n", 42);
	printf("%.3d\n\n", 42);

	printf("%.4d\n", 42);
	printf("%.4d\n\n", 42);
	
	printf("%.5d\n", 42);
	printf("%.5d\n\n", 42);

	printf("%x\n", -8);

	// negative numbers: precision pads only the digits, width+0 pads the whole field
	printf("|%05d|\n", -42);  // |-0042|   width=5 includes the “-” so you get 2 zeros  
	printf("|%.5d|\n", -42);  // |-00042|  precision=5 applies to the “42” only, then sign  

	// zero value with precision zero vs zero‐flag
	printf("|%0d|\n", 0);     // |0|       no width specified, zero‐flag ignored, prints “0”  
	printf("|%.0d|\n", 0);    // ||        precision=0 + value=0 → prints nothing  

	// strings: precision truncates, zero‐flag is ignored  
	printf("|%.3s|\n", "hello"); // |hel|  
	printf("|%3s|\n", "hi");    // |  hi|   zero‐flag doesn’t pad strings, so spaces

	//printf("|%.3c|\n", 'c');

	//char hello[] = "hello";
	//printf("|%.3p|\n", hello);

	//printf("|hello%3%|\n");

	// combine width+precision to see zero‐flag vanish
	printf("|%08d|\n",   123); // |00000123|  zero-flag pads to width when no precision  
	return (0);
}