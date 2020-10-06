#include "menger.h"

void generate_sponge_at_resolution(char **sponge, int size, int level);
void fill_unit(char **sponge, int row, int col, int scale, char fill);
void free_grid(int **grid, int size);
char **alloc_grid(int size);

/**
 * menger - Generate a menger sponge.
 * @level: The level of recursion in generating the menger sponge.
 */
void menger(int level)
{
    int y, x, size, resolution = 1;
	char **sponge;

    /* Calculate sponge size based on*/
    size = pow(3, level);
    printf("Sponge size is %i\n", size);

	/* Generate blank 2D array for complete sponge */
	sponge = alloc_grid(size);

	while (level > 0)
	{
		generate_sponge_at_resolution(sponge, size, resolution);
		resolution *= 3;
		level--;
	}
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
 * generate_sponge_at_resolution - Generate a menger sponge.
 * @sponge: Empty 2D within which to initialize sponge.
 * @size: Sponge size.
 * @resolution: Resolution of sponge being generated.
 *
 * Return: pointer to 2D array on Success, NULL on Fail
 */
void generate_sponge_at_resolution(char **sponge, int size, int resolution)
{
	int row, col;
	char fill;
	char unit[3][3] = {
		{'#', '#', '#'},
		{'#', ' ', '#'},
		{'#', '#', '#'}
	};

	for (row = 0; row < size; row += resolution)
	{
		for (col = 0; col < size; col += resolution)
		{
			fill = unit[row / (size / 3)][col / ( size / 3)];
			fill_unit(sponge, row, col, resolution, fill);
		}
	}
}

void fill_unit(char **sponge, int row, int col, int unit_size, char fill)
{
	int y, x;

	for (y = 0; y < (unit_size); y++)
	{
		for (x = 0; x < (unit_size); x++)
		{
			sponge[row + y][col + x] = fill;
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