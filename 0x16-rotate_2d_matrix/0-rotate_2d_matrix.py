#!/usr/bin/python3
""" Funtion to rotate a 2D matrix clockwise.
"""


def rotate_2d_matrix(matrix):
    """ Rotates a 2D matrix clockwise.
    """
    size = len(matrix)
    step = size - 1

    for x in range(0, int(size / 2)):
        for y in range(x, step - x):

            temp = matrix[x][y]

            matrix[x][y] = matrix[step - y][x]

            matrix[step - y][x] = matrix[step - x][step - y]

            matrix[step - x][step - y] = matrix[y][step - x]

            matrix[y][step - x] = temp
