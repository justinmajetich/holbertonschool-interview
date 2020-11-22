#!/usr/bin/python3
"""
    Determine how many units of rain can be contained within array's walls.
"""


def find_volume_between_walls(walls, left, right):
    """
        Find the number of units that may be contained between walls.
    """
    left_wall = walls[left]
    right_wall_index = 0
    filled_space = 0
    width = 0

    for i in range(left + 1, right):
        if walls[i] < left_wall:
            filled_space += walls[i]
        else:
            right_wall_index = i
            break
        width += 1
    
    return [(left_wall * width) - filled_space, right_wall_index]

def rain(walls):
    """
        Determine how many units of rain can be contained within array's walls.
    """
    totlal_volume = 0
    size = len(walls)


    # If list is empty return 0.
    if size <= 0:
        return totlal_volume

    # Iterate through list to find walls.
    for i in range(size):
        if walls[i] >= 1:
            volume_data = find_volume_between_walls(walls, i, size)
            totlal_volume += volume_data[0]
            i = volume_data[1] - 1

    return totlal_volume