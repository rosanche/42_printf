#include "printf.h"

int main()
{
    ft_printf("mine: %.5i%%%17.2x%014.0uNAu%03u\n", -218032260, 0, -2147483647, 0);
	   printf("real: %.5i%%%17.2x%014.0uNAu%03u\n", -218032260, 0, -2147483647, 0);
}