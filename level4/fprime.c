#include <stdio.h>
#include <stdlib.h>

void	fprime(char *str)
{
	int num;
	int div;

	div = 2;
	num = atoi(str);
	if (num == 1)
		printf("1");
	if (num <= 1)
		return;
	while (div <= num)
	{
		if (num % div == 0)
		{
			printf("%d", div);
			if (num == div)
				return;
			printf("*");
			num /= div;
			div = 1;
		}
		div++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		fprime(argv[1]);
	printf("\n");
	return (0);
}
