
#include <stdarg.h>
#include <stdio.h>

int average(int argc, ...);

int main(void)
{
	printf("%i", average(4, 5, 6, 33, 100));
}

int average(int argc, ...)
{
	int arr[argc];
	int i = 0;
	va_list	arglist;

	va_start(arglist, argc);
	while (i < argc)
	{
		arr[i] = va_arg(arglist, int);
		i++;
	}
	va_end(arglist);
	int average = 0;
	i = 0;
	while (i < argc)
	{
		average += arr[i];
		i++;
	}
	average /= argc;
	return (average);
}