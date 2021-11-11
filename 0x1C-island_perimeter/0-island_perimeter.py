#!/usr/bin/python3
"""
Island Perimeter Function for 0x1C - Island perimeter.
"""


def island_perimeter(grid):
        """Checks grid array for 1's, then counts adjacent 0's in
        cardinal directions.  Returns that count upon iterating through
        array."""

        p = 0
        for r in range(len(grid)):
                for c in range(len(grid)):
                        if grid[r][c] == 1:
                                if grid[r - 1][c] == 0:
                                        p += 1
                                if grid[r][c + 1] == 0:
                                        p += 1
                                if grid[r + 1][c] == 0:
                                        p += 1
                                if grid[r][c - 1] == 0:
                                        p += 1
        return p
