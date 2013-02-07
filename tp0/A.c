#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int lines, columns;
int **matrix, **new;

void showMatrix()
{
	int i, j;

	printf("%d %d\n", lines, columns);
	for (i = 0; i < lines; ++i)
	{
		for (j = 0; j < columns; ++j)
			printf("%d ", new[i][j]);
		printf("\n");
	}
}

void transform()
{
	int i, j, halfLines, halfColumns;

	new = (int**) malloc (lines * sizeof(int*));
	for (i = 0; i < lines; ++i)
		new[i] = (int*) malloc (columns * sizeof(int));

	halfColumns = ceil(columns / 2.0);
	halfLines = ceil(lines / 2.0);

	for (i = 0; i < lines - halfLines; ++i)
		for (j = 0; j < columns - halfColumns; ++j)
			new[i][j] = matrix[halfLines+i][halfColumns+j];

	for (i = 0; i < lines - halfLines; ++i)
		for (j = 0; j < halfColumns; ++j)
			new[i][columns-halfColumns+j] = matrix[i+halfLines][j];

	for (i = 0; i < halfLines; ++i)
		for (j = 0; j < halfColumns; ++j)
			new[i+lines-halfLines][j+columns-halfColumns] = matrix[i][j];

	for (i = 0; i < halfLines; ++i)
		for (j = 0; j < columns - halfColumns; ++j)
			new[i+lines-halfLines][j] = matrix[i][j+halfColumns];
	
	showMatrix();
}

int main(int argc, char** argv)
{
	int i, j;

	scanf("%d %d", &lines, &columns);

	matrix = (int**) malloc (lines * sizeof(int*));

	for (i = 0; i < lines; ++i)
	{
		matrix[i] = (int*) malloc (columns * sizeof(int));
		for (j = 0; j < columns; ++j)
			scanf("%d", &matrix[i][j]);
	}

	transform();

	for (i = 0; i < lines; ++i)
		free(matrix[i]);
	free(matrix);

	return 0;
}
