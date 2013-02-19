#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N, f1 = 0, f2 = 0, sum = 0;
int *values, *aux, *aux2;

int solve()
{
	int i, j;

	if (N == 1)
		return values[0];
	if (N == 0)
		return 0;


	aux = (int*) calloc (sum+1, sizeof(int));
	aux2 = (int*) calloc (sum+1, sizeof(int));

	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < sum + 1; ++j)
			aux2[j] = aux[j];

		aux2[values[i]] = 1;
		for (j = 0; j < sum + 1; ++j)
			if (aux[j] && aux2[j+values[i]] < sum+1)
				aux2[j+values[i]] = 1;

		for (j = 0; j < sum + 1; ++j)
			aux[j] = aux2[j];
	}

	if (aux[sum/2])
		return sum % 2;

	j = ceil(sum / 2.0);
	for (i = 0; i < j; ++i)
		if (aux[j-i])
			return 2 * i - sum % 2;
}

int main(int argc, char** argv)
{
	int i;

	scanf("%d", &N);
	values = (int*) malloc (N * sizeof(int));

	for (i = 0; i < N; ++i)
	{
		scanf("%d", &values[i]);
		sum += values[i];
	}

	printf("%d\n", solve());

	return 0;
}
