
#include <stdio.h>
#include <string.h>

int main(void)
{
	// %c
	//printf("|%.3c|\n", 'c'); 		// WRONG .3c
	//printf("|%03c|\n", 'c'); 		// WRONG 03c
	printf("my age: %i\n", 500);  // RIGHT  3c
	printf("-3c -> |%-3c|\n", 'c'); // RIGHT -3c
	printf("-3c -> |%-3c|\n\n", '\0'); // 
	
	char *hi = NULL;
	// strings: precision truncates, zero‐flag is ignored  
	printf(".3s -> |%.3s|\n", "hello"); // |hel|  
	printf(" 3s -> |%3s|\n", "hi");      // |  hi|   zero‐flag doesn’t pad strings, so spaces
	printf("-3s -> |%3s|\n", "hi");      
	printf("-3s -> |%3s|\n", "\0");      
	printf("-3s -> |%3s|\n\n", hi);      

	// %d %i
	printf("05d ->  |%05d|\n", 42);
	printf(".5d ->  |%.5d|\n", 42);
	printf("05d ->  |%05d|\n", -42);  // |-0042|   width=5 includes the “-” so you get 2 zeros  
	printf(".5d -> |%.5d|\n", -42);   // |-00042|  precision=5 applies to the “42” only, then sign  
	printf(" 0d -> |%0d|\n", 0);      // |0|       no width specified, zero‐flag ignored, prints “0”  
	printf(".0d -> |%.0d|\n\n", 0);   // ||        precision=0 + value=0 → prints nothing
	// %d %i
	printf("505d ->  |%505d|\n", 99599599);
	printf(".5d ->  |%0d|\n", 99599599);
	printf("100.5d ->  |%-100d|\n", 599599);
	

	char hello[] = "hi";
	// %p
	printf("p -> %p\n", hello);
	printf("p -> %p\n", NULL);
	//printf("%05p", hello); // 0 flag %p WRONG
	//printf("%.5p", hello); // . flag %p WRONG

	

	return (0);
}