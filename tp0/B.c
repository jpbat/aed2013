#include <stdio.h>

int main(int argc, char** argv)
{
	float x, result = 1.0;
	int n, counter = 0;

	scanf("%f %d", &x, &n);

	if (n < 0)
	{
		n *= -1;
		x = 1 / x;
	}

	while (n > 0)
	{
		if (n % 2 == 1)
			result *= x;

		x *= x;

		if (n > 1)
			counter += n % 2 + 1;

		n /= 2;
	}

	printf("%.2f\n%d\n", result, counter);

	return 0;
}
