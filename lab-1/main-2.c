#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	x, y, z;

	if (argc < 4)
	{
		printf("%s x y z", argv[0]);
		return 0;
	}
	x = atoi(argv[1]);
	y = atoi(argv[2]);
	z = atoi(argv[3]);
	printf("x = %d\ny = %d\nz = %d\n", x, y, z);
	if (x + y > z && x + z > y && y + z > x && (x > 0 && y > 0 && z > 0))
		printf("Tringle with those sides exist!\n");
	else
		printf("Triangle doesn`t exist\n");
}
