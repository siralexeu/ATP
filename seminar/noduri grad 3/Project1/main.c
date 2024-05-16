#include<stdio.h>
#include<stdlib.h>

int** construire(FILE* f, int n, int m)
{
	int** mat = (int**)malloc(n * sizeof(int**));
	for (int i = 0; i < n; i++) {
		mat[i] = (int*)calloc(n, sizeof(int**));
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		fscanf(f, "%d %d", &x, &y);
		mat[x - 1][y - 1] = 1;
		mat[y - 1][x - 1] = 1;
	}
	return mat;
}

void afisare(int** mat, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d", mat[i][j]);
		}
		printf("\n");
	}

}

void nodurigrad(int** mat, int n)
{
	int nodurigrad = 0;
	for (int i = 0; i < n; i++)
	{
		int grad = 0;
		for (int j = 0; j < n; j++)
		{
			if (mat[i][j] == 1)
				grad++;
		}
		if (grad == 3)
		{
			nodurigrad++;
			printf("%d ", i + 1);
		}
	}
}

int main()
{
	FILE * f = fopen("graf.txt", "r");
	if (f == NULL) return 1;

	int n, m;
	fscanf(f, "%d %d", &n, &m);

	int** mat= construire(f, n, m);
	fclose(f);

	afisare(mat, n);
	nodurigrad(mat, n);

	for (int i = 0; i < n; i++)
	{
		free(mat[i]);
	}
	free(mat);

	return 0;
}