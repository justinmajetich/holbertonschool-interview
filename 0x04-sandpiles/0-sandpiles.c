#include "sandpiles.h"

void sandpiles_topple(int grid[3][3]);
int sandpiles_stability(int grid[3][3]);
void add_sandpiles(int grid1[3][3], int grid2[3][3]);
void print_grid(int grid[3][3]);

/**
 * sandpiles_sum - Find the stable sum of two stable sandpile grids
 * @grid1: First grid
 * @grid2: Second grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{

	/* Add sandpiles together */
	add_sandpiles(grid1, grid2);

	/* Check if sum pile is stable */
	while (sandpiles_stability(grid1))
	{
		/* If sum is unstable, print and topple */
		sandpiles_topple(grid1);
	}
}

/**
 * sandpiles_topple - Topple sandpiles until grid is stable
 * @grid: Grid to topple
 */
void sandpiles_topple(int grid[3][3])
{
	int buffer[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	int x, y;
	/* Iterate through grid toppling sandpile overflow (size > 3) */
	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			/* Check if sandpile is greater than 3 */
			if (grid[y][x] > 3)
			{
				/* Topple four grains from sandpile */
				grid[y][x] -= 4;

				/* Distribute 1 grain to left pile, if exists */
				if (x - 1 >= 0)
					buffer[y][x - 1] += 1;

				/* Distribute 1 grain to above pile, if exists */
				if (y - 1 >= 0)
					buffer[y - 1][x] += 1;

				/* Distribute 1 grain to right pile, if exists */
				if (x + 1 <= 2)
					buffer[y][x + 1] += 1;

				/* Distribute 1 grain to below pile, if exists */
				if (y + 1 <= 2)
					buffer[y + 1][x] += 1;
			}
		}
	}
	add_sandpiles(grid, buffer);
}

/**
 * sandpiles_stability - Check a sandpiles' stability
 * @grid: Grid to check
 *
 * Return: 0 if stable; 1 if unstable
 */
int sandpiles_stability(int grid[3][3])
{
	int x, y;
	/*
	 * Loop through grid1 adding the value
	 * at the concurrent index in grid2
	 */
	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			/* If sandpile is unstable */
			if (grid[y][x] > 3)
			{
				print_grid(grid);
				return (1);
			}
		}
	}
	return (0);
}

/**
 * add_sandpiles - Add two grids of sandpiles together
 * @grid1: Grid to add to
 * @grid2: Grid to add
 */
void add_sandpiles(int grid1[3][3], int grid2[3][3])
{
	int x, y;
	/*
	 * Loop through grid1 adding the value
	 * at the concurrent index in grid2
	 */
	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			grid1[y][x] += grid2[y][x];
		}
	}
}

/**
 * print_grid - Prints a grid
 * @grid: Grid to be printed
 */
void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");

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
