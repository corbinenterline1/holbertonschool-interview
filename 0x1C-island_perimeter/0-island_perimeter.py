#!/usr/bin/python3
"""
Island Perimeter Function for 0x1C - Island perimeter.
"""


def island_perimeter(grid):
    """
    Checks grid array for 1's (land), then counts adjacent 0's (water)
    to that index with 1 in cardinal directions, clockwise.
    Returns that count (perimeter) upon iterating through array.
    """

    p = 0
    for r in range(len(grid)):
        for c in range(len(grid[r])):
            if (grid[r][c] == 1):
                if (r <= 0 or grid[r - 1][c] == 0):
                    p += 1
                if (c >= len(grid[r]) - 1 or grid[r][c + 1] == 0):
                    p += 1
                if (r >= len(grid) - 1 or grid[r + 1][c] == 0):
                    p += 1
                if (c <= 0 or grid[r][c - 1] == 0):
                    p += 1
    return p
