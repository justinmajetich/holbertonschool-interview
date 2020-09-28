#include "slide_line.h"

/**
 * slide_line - Add identical numbers left or right in an array.
 * @line: Array to be manipulated.
 * @size: Size of array.
 * @direction: Direction in which to perform the additions.
 * 
 * Return: 1 if successful, 0 if unsuccessful.
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t current, look_ahead;
    int addition_made = 0; /* 0 = false, 1 = true */

    /* Check for invalid direction */
    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return (0);

    /* Move through line array left to right */
    if (direction == SLIDE_LEFT)
    {
        for (current = 0; current < size; current++)
        {
            /* If number is 0, look ahead */
            if (line[current] == 0)
            {
                look_ahead = current;
                while (look_ahead < size)
                {
                    if (line[look_ahead] != 0)
                    {
                        /* When next non-zero value is found, move value left, increment past, and break */
                        line[current] = line[look_ahead];
                        line[look_ahead] = 0;
                        break;
                    }
                    look_ahead++;                
                }
            }

            if (line[current] != 0)
            {
                if (current - 1 < size && line[current] == line[current - 1] && addition_made == 0)
                {
                    line[current - 1] *= 2;
                    line[current] = 0;
                    current--;
                    addition_made = 1;
                }
                else
                    addition_made = 0;
            }
        }
    }
    return (1);
}