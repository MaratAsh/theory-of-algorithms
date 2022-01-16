#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	first, last;
	long long	mult;

	if (argc == 3)
	{
		first = 2;
		last = 30;
	}
	else
	{
		first = atoi(argv[1]);
		last = atoi(argv[2]);
	}
	mult = 1;
	for (; first <= last; ++first)
	{
		if (first % 2 == 0)
			mult = mult * first;
	}
	printf("Result:	%lld\n", mult);
}
