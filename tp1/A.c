#include <stdio.h>
#include <stdlib.h>

int N, f1 = 0, f2 = 0;
int *values;

void solve()
{
	int i;

	if (N > 0)
		f1 += values[0];

	for (i = 1; i < N; ++i)
	{
		if(f1 < f2)
			f1 += values[i];
		else
			f2 += values[i];
	}

	printf("%d\n", abs(f1-f2));
}

int main(int argc, char** argv)
{
	int i;

	scanf("%d", &N);
	values = (int*) malloc (N * sizeof(int));

	for (i = 0; i < N; ++i)
		scanf("%d", &values[i]);

	solve();

	return 0;
}
