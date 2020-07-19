#!/usr/bin/python3
"""
    This program will determine whether or not a set of boxes
    together contain the keys to unlock all boxes
"""

def canUnlockAll(boxes):
    """ Determine if all boxes can be unlocked """
    keys = [0]
    keysNeeded = [i[0] for i in enumerate(boxes)]

    # Collect keys from all unlockable boxes beginning with 0
    collectKeys(boxes, keys)

    # Return true or false depending on whether keys present match key needed
    return sorted(keys) == keysNeeded


def collectKeys(boxes, keys, key=0):
    """ Recursively collect all unique keys from all boxes """
    for newKey in boxes[key]:
        if newKey not in keys:
            keys.append(newKey)
            collectKeys(boxes, keys, newKey)