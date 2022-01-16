#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	a, b, c;
	int	p;
	unsigned long long	S;

	if (argc < 3)
	{
		printf("%s a b c", argv[0]);
		return 0;
	}
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	c = atoi(argv[3]);
	printf("a = %d\nb = %d\nc = %d\n", a, b, c);
	p = (a + b + c) / 2;
	S = pow(p * (p - a) * (p - b) * (p - c), 0.5);
	printf("S = %llu", S);
}
