#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
	printf("\n");
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 * Tiles with sand > 3 "topple" into the 4 adjacent tiles, including off edge
 * the sand falls in cardinal directions.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, topple = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
			if (grid1[i][j] > 3)
				topple = 1;
		}
	}
	if (topple)
	{
		printf("=\n");
		print_grid(grid1);
		sift(grid1);
	}
}

/**
 * sift - Sifts the toppled sandpile down to a stable level.
 * @grid1: Grid to be sifted.
 */
void sift(int grid1[3][3])
{
	int i, j, topple = 0;
	int sandbucket[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] < 4)
				sandbucket[i][j] += grid1[i][j];
			else if (grid1[i][j] >= 4)
			{
				sandbucket[i][j] += grid1[i][j] - 4;
				if (i > 0)
					sandbucket[i - 1][j] += 1;
				if (j > 0)
					sandbucket[i][j - 1] += 1;
				if (i < 2)
					sandbucket[i + 1][j] += 1;
				if (j < 2)
					sandbucket[i][j + 1] += 1;
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (sandbucket[i][j] > 3)
				topple = 1;
			grid1[i][j] = sandbucket[i][j];
		}
	}
	if (topple == 1)
	{
		printf("=\n");
		print_grid(grid1);
		sift(grid1);
	}
}
