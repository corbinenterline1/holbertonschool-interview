#!/usr/bin/env python3
"""
The N queens puzzle is the challenge of
placing N non-attacking queens on an NN chessboard.
"""

import sys


def valid_position(i, j):
    """
    Checks if position is valid
    """
    for q in range(0, N):
        if board[i][q] == 1 or board[q][j] == 1:
            return True
    for q in range(0, N):
        for diag in range(0, N):
            if (q + diag == i + j) or (q - diag == i - j):
                if board[q][diag] == 1:
                    return True
    return False


def nqueen(n, start):
    """
    Solves the N queens problem. N >= 4
    """
    if n == 0:
        return True
    for i in range(0, N):
        if i > 0:
            start = 0
        for j in range(start, N):
            if (not(valid_position(i, j))) and (board[i][j] != 1):
                board[i][j] = 1
                if nqueen(n - 1, start):
                    return True
                board[i][j] = 0
    return False

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
    for i in range(0, N):
        board = [[0] * N for _ in range(N)]
        nqueen(N, i)
        solution = []
        for row in range(0, N):
            for col in range(0, N):
                if board[row][col] == 1:
                    solution.append([row, col])
        if solution[0][1] == i:
            print(solution)