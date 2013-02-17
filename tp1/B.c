#include <stdio.h>
#include <stdlib.h>

int N;
int *values;

int solve(pos, f1, f2)
{
	int i, aux, t1, t2;

	if (pos == N)
		return abs(f1-f2);
	else
	{
		t1 = solve(pos+1, f1 + values[pos], f2);
		t2 = solve(pos+1, f1, f2 + values[pos]);
		return t1 < t2 ? t1 : t2;
	}	
}

int main(int argc, char** argv)
{
	int i, f1 = 0, f2 = 0;

	scanf("%d", &N);
	values = (int*) malloc (N * sizeof(int));

	for (i = 0; i < N; ++i)
		scanf("%d", &values[i]);

	printf("%d\n", solve(0, 0, 0));

	return 0;
}
