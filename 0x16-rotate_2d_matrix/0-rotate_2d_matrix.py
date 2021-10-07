#!/usr/bin/python3
"""
0x16 - Rotate 2D Matrix.
"""


def rotate_2d_matrix(matrix):
    """Rotates 2d Matrix 90 degrees clockwise."""
    for i in range(len(matrix)):
        for j in range(i, len(matrix)):
            if i != j:
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    for i in matrix:
        i.reverse()
