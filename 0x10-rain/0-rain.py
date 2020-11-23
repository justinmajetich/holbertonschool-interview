#!/usr/bin/python3
"""
    Determine how many units of rain can be contained within array's walls.
"""


def rain(walls):
    """
        Determine how many units of rain can be contained within array's walls.
    """
    water_temp = 0
    water = 0
    size = len(walls)
    prev_wall = 0

    # If list is empty return 0.
    if size <= 0:
        return water_temp

    # Iterate through list to find walls.
    for i in range(size):

        if walls[i] >= walls[prev_wall]:
            prev_wall = i
            water_temp = 0
        else:
            water += walls[prev_wall] - walls[i]
            water_temp += walls[prev_wall] - walls[i]

    if prev_wall < size - 1:

        water -= water_temp
        prev_pass_peak = prev_wall
        prev_wall = size - 1

        for i in range(size - 1, prev_pass_peak, -1):

            if walls[i] >= walls[prev_wall]:
                prev_wall = i
            else:
                water += walls[prev_wall] - walls[i]

    return water
