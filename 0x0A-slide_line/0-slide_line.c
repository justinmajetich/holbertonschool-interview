#include "slide_line.h"

int slide_left(int *line, size_t size);
int slide_right(int *line, size_t size);

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
    if (direction == SLIDE_LEFT)
        return (slide_left(line, size));
    else if (direction == SLIDE_RIGHT)
        return (slide_right(line, size));
    else
        return (0);
}

/**
 * slide_left - Add identical numbers left in an array.
 * @line: Array to be manipulated.
 * @size: Size of array.
 */
int slide_left(int *line, size_t size)
{
    size_t current, look_ahead;
    int addition_made = 0; /* 0 = false, 1 = true */

    /* Move through line array left to right */
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

        /* If current is non-zero, check for indentical preceding number to add to */
        if (line[current] != 0)
        {
            if (current != 0 && line[current] == line[current - 1] && addition_made == 0)
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
    return (1);
}

/**
 * slide_right - Add identical numbers right in an array.
 * @line: Array to be manipulated.
 * @size: Size of array.
 */
int slide_right(int *line, size_t size)
{
    int current, look_ahead;
    int addition_made = 0; /* 0 = false, 1 = true */

    /* Move through line array right to left */
    for (current = size - 1; current >= 0; current--)
    {
        /* If number is 0, look ahead */
        if (line[current] == 0)
        {
            look_ahead = current;
            while (look_ahead >= 0)
            {
                if (line[look_ahead] != 0)
                {
                    /* When next non-zero value is found, move value left, increment past, and break */
                    line[current] = line[look_ahead];
                    line[look_ahead] = 0;
                    break;
                }
                look_ahead--;                
            }
        }

        /* If current is non-zero, check for indentical following number to add to */
        if (line[current] != 0)
        {
            if (current + 1 < (int)size && line[current] == line[current + 1] && addition_made == 0)
            {
                line[current + 1] *= 2;
                line[current] = 0;
                current++;
                addition_made = 1;
            }
            else
                addition_made = 0;
        }
    }
    return (1);
}