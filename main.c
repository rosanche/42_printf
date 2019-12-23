#include "printf.h"

int main()
{
	int mine;
	int real;

	// ft_printf("Antoine adore %18s des grosses %-2s, il en a deja suce %10d dans sa vie\n", "sucer", "bites", 20);
	//    printf("Antoine adore %18s des grosses %-2s, il en a deja suce %10d dans sa vie\n", "sucer", "bites", 20);
	// ft_printf("result: %03.7d\n", -2375);
	mine = ft_printf("Antoine adore %18s des grosses %-2s, il en a deja suce %8.2s\n", "sucer", "bites", "pleins");
	real = printf("Antoine adore %18s des grosses %-2s, il en a deja suce %8.2s\n", "sucer", "bites", "pleins");
	printf("mine: %d\nreal: %d", mine, real);
}