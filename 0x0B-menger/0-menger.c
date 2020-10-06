#include "menger.h"

void generate_sponge(char **sponge, int row, int col, int size);
void free_sponge(char **grid, int size);
void print_sponge(char **sponge, int size);
char **alloc_grid(int size);

/**
 * menger - Generate a menger sponge.
 * @level: The level of recursion in generating the menger sponge.
 */
void menger(int level)
{
	int size;
	char **sponge = NULL;

    /* Calculate sponge size based on it's level. */
	size = pow(3, level);

	if (size > 0)
	{
		/* Generate blank 2D array to hold completed sponge. */
		sponge = alloc_grid(size);

		if (size > 1)
			generate_sponge(sponge, 0, 0, size);
		else
			sponge[0][0] = '#';

		print_sponge(sponge, size);

		free_sponge(sponge, size);
	}
}

/**
 * generate_sponge - Recursively generate a menger sponge on a blank grid.
 * @sponge: Empty 2D within which to initialize sponge.
 * @row: Starting row index.
 * @col: Starting column index.
 * @size: Sponge size.
 */
void generate_sponge(char **sponge, int row, int col, int size)
{
	int x, y, scalar = size / 3;
	char unit[3][3] = {
		{'#', '#', '#'},
		{'#', ' ', '#'},
		{'#', '#', '#'}
	};

	/* Iterate through given segment of sponge */
	for (y = 0; y < size; y += scalar)
	{
		for (x = 0; x < size; x += scalar)
		{
			/* If sponge is not at smallest unit, continue recursive subdivision */
			if (size > 3)
			{
				/*
				 * This if statement scales the index of the larger sponge segment
				 * being inspected to a proportional index on the base sponge unit.
				 */
				if (unit[y / scalar][x / scalar] == '#')
					generate_sponge(sponge, row + y, col + x, scalar);
			}
			else /* If smallest unit reached, copy single unit onto sponge */
			{
				sponge[row + x][col + y] = unit[x][y];
			}
		}
	}
}

/**
 * alloc_grid - initialize square 2D array
 * @size: Grid size.
 *
 * Return: pointer to 2D array on Success, NULL on Fail
 */
char **alloc_grid(int size)
{
	char **grid;
	int i, j;

	/* allocate memory for grid (pointer to pointer) */
	grid = malloc(sizeof(char *) * size);
	if (grid == NULL)
		return (NULL);

	/* allocate memory for *grid (pointer to int) */
	for (i = 0; i < size; i++)
	{
		*(grid + i) = malloc(sizeof(char) * size);
		if (*(grid + i) == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(grid);
				free(*(grid + j));
			}
			return (NULL);
		}
	}

	/* initialize all elements to 0 */
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			grid[i][j] = ' ';
	return (grid);
}

/**
 * free_sponge - Free a 2D grid.
 * @grid: Grid to free.
 * @size: Size of grid.
 */
void free_sponge(char **grid, int size)
{
	int i;

	for (i = 0; i < size; i++)
		free(*(grid + i));
	free(grid);
}

/**
 * print_sponge - Print a menger sponge.
 * @sponge: Sponge to print.
 * @size: Size of sponge being printed.
 */
void print_sponge(char **sponge, int size)
{
	int x, y;

	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			putchar(sponge[y][x]);
		}
		putchar('\n');
	}
}
