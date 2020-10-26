#!/usr/bin/python3
""" Determines how to safely position N queens on a board of N size """


import sys


def solve_recursively(board, col):
    """ Safely place queens column by column.
        The function will continue to to backtrack,
        even after a solution is printed, until
        all solutions have been printed.
    """

    # Base case (all queens safely placed)
    if col == len(board):
        print_solution(board, len(board))
        return

    for row in range(len(board)):
        # Validate current placement as safe
        if validate_placement(board, col, row):

            # Place queen
            board[row][col] = 1

            # Recurse to place in next column
            solve_recursively(board, col + 1)

            # Backtrack
            board[row][col] = 0


def validate_placement(board, col, row):
    """ Determine if the queen can safely be placed """

    # Check for leftward horizontal conflict
    for x in range(col, -1, -1):
        if board[row][x] == 1:
            return False

    # Check for upward diagnol conflict
    x = col
    for y in range(row, -1, -1):
        if board[y][x] == 1:
            return False
        x -= 1

    # Check for downward diagnol conflict
    x = col
    for y in range(row, len(board)):
        if board[y][x] == 1:
            return False
        x -= 1

    return True


def print_solution(board, size):
    """ Prints solution of safe queen placement """

    placements = []

    for row in range(size):
        for col in range(size):
            if board[row][col] == 1:
                placements.append([row, col])

    print(placements)


def validate_args(args):
    """ Validate user arguments """

    # Program takes 2 arguments
    if len(args) is not 2:
        print('Usage: nqueens N')
        sys.exit(1)

    # n must be an integer
    try:
        n = int(args[1])
    except ValueError:
        print('N must be a number')
        sys.exit(1)

    # n must be >= 4
    if n < 4:
        print('N must be at least 4')
        sys.exit(1)


def print_board(board):
    """ Print board for debug """
    for row in board:
        print(row)


# Assign and validate user args
validate_args(sys.argv)
n = int(sys.argv[1])

# Generate board of N size
board = [[0 for col in range(n)] for row in range(n)]

# Solve board if possible
solve_recursively(board, 0)
