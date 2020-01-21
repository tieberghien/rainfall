#include <stdio.h>

int main(int ac, char **av)
{
	printf("Variable %s at address %p\n", av[1], getenv(av[1]));
}
