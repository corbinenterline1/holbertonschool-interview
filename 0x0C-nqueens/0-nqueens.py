#!/usr/bin/python3
"""
The N queens puzzle is the challenge of
placing N non-attacking queens on an NN chessboard.
"""

import sys


def attacked(queens, i, j):
    """
    Checks queens positioning!
    """
    for q in queens:
        if q[0] == i or q[1] == j:
            return False
        if abs(q[0] - i) == abs(q[1] - j):
            return False
    return True


def nqueen(rows, queens=[], j=0):
    """
    Places the queen
    """
    if len(queens) == N:
        print(queens)
        return
    for i in rows:
        if attacked(queens, i, j):
            nqueen(rows.difference({i}), queens + [[i, j]], j + 1)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    try:
        N = int(sys.argv[1])
    except:
        print("N must be a number")
        exit(1)

    if N < 4:
        print("N must be at least 4")
        exit(1)

    nqueen(set(range(N)))