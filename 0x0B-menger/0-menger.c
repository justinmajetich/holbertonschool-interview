#include "menger.h"

void generate_sponge(char **sponge, int row, int col, int size);
void free_grid(int **grid, int size);
char **alloc_grid(int size);

/**
 * menger - Generate a menger sponge.
 * @level: The level of recursion in generating the menger sponge.
 */
void menger(int level)
{
    int y, x, size;
	char **sponge;

    /* Calculate sponge size based on*/
    size = pow(3, level);
    printf("Sponge size is %i\n", size);

	/* Generate blank 2D array for complete sponge */
	sponge = alloc_grid(size);

	generate_sponge(sponge, 0, 0, size);

	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			putchar(sponge[y][x]);
		}
		putchar('\n');
	}
}

/**
 * generate_sponge - Generate a menger sponge.
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

	for (y = 0; y < size; y += scalar)
	{
		for (x = 0; x < size; x += scalar)
		{
			if (size > 3)
			{
				if (unit[(row + y) / scalar][(col + x) / scalar] == '#')
					generate_sponge(sponge, row + y, col + x, scalar);
			}
			else
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
 * free_grid - Free a 2D grid.
 * @grid: Grid to free.
 * @size: Size of grid.
 */
void free_grid(int **grid, int size)
{
	int i;

	for (i = 0; i < size; i++)
		free(*(grid + i));
	free(grid);
}