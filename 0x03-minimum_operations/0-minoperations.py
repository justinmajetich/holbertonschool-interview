#!/usr/bin/python3
""" Calculate the minimun operations necessary to copy/paste
    given character to appear n times.
"""


def minOperations(n):
    """ Calculate the minimun operations necessary to copy/paste
        given character to appear n times.
    """
    operationCount = 0
    _file = 'H'
    buffer = ''

    while len(_file) < n:

        # If target size n is cleaning divisible by current size
        if n % len(_file) == 0:
            # Copy file contents to buffer
            buffer = _file
            operationCount += 1

        # Paste buffer to file
        _file += buffer
        operationCount += 1

    return operationCount
