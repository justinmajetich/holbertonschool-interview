#!/usr/bin/python3
""" Determines if a data set represents valid UTF-8 encoding.
"""


def validUTF8(data):
    """ Determine if data has valid UTF-8 encoding.
    """
    expectedBytesRemaining = -1
    insideCharacter = False

    for number in data:
        # Convert number to binary string representation.
        binaryString = str(format(number, '08b'))

        # Break binary number into list of individual integer digits.
        bits = list(map(int, binaryString))

        # If leading bit denotes single-byte character.
        if bits[0] == 0:
            # If currently validating character, encoding is invalid.
            if insideCharacter:
                return False

        # If leading bit denotes new or continuing multi-byte character (is 1).
        else:
            # If continuing character.
            if insideCharacter:
                if bits[1] != 0:  # Invalid continuation byte (valid is "10").
                    return False
                else:  # Is valid continuation byte.
                    if expectedBytesRemaining == 1:
                        expectedBytesRemaining = -1
                        insideCharacter = False
                    else:
                        expectedBytesRemaining -= 1

            else:  # New multi-byte character.
                #  Determine byte size of new character.
                for bit in bits:
                    if bit != 0:
                        expectedBytesRemaining += 1

                if expectedBytesRemaining < 1 or expectedBytesRemaining > 3:
                    return False

                insideCharacter = True

    # Verify that data set did not end with incomplete character.
    if expectedBytesRemaining != -1:
        return False
    else:
        return True
