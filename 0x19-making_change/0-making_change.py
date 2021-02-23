#!/usr/bin/python3
""" Determine least amount of coins needed to make change.
"""


def makeChange(coins, total):
    """ Determine least amount of coins needed to make change.
    """
    coin_count = 0

    if total <= 0:
        return 0

    # Sort list of coins in decending order.
    coins = sorted(coins, reverse=True)

    # Cycle through all available coins to make change.
    for coin in coins:
        while total >= coin:
            total -= coin
            coin_count += 1

    # If total is not met perfectly, return -1.
    if total > 0:
        return -1
    else:
        return coin_count
