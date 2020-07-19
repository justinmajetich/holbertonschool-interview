#!/usr/bin/python3
"""
    This program will determine whether or not a set of boxes
    together contain the keys to unlock all boxes
"""


def canUnlockAll(boxes):
    """ Determine if all boxes can be unlocked """
    if boxes and type(boxes) == list:
        keys = [0]
        keysNeeded = [i[0] for i in enumerate(boxes)]

        # Collect keys from all unlockable boxes beginning with 0
        collectKeys(boxes, keys)

        # Return true or false depending on whether keys present match key needed
        return sorted(keys) == keysNeeded
    else:
        return False


def collectKeys(boxes, keys, key=0):
    """ Recursively collect all unique keys from all boxes """
    if type(boxes[key]) == list:
        for newKey in boxes[key]:
            if type(newKey) == int and newKey not in keys and (newKey > -1 and newKey < len(boxes)):
                keys.append(newKey)
                collectKeys(boxes, keys, newKey)
