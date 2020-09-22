#!/usr/bin/python3
""" Determines if a data set represents valid UTF-8 encoding.
"""

def validUTF8(data):
    """ Determine if data has valid UTF-8 encoding.
    """
    for number in data:
        if number > 127:
            return False
    return True