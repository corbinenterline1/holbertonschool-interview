#!/usr/bin/python3

"""
Pascal function
"""
def pascal_triangle(n):
    """
    Creates a pascal triangle
    """
    a = []
    new = []
    for line in range(1, n + 1):
        C = 1; # used to represent C(line, i)
        for i in range(1, line + 1):
            # Lines start with 1
            new.append(C)
            # print(C, end= " ")
            C = int(C * (line - i) / i)
        a.append(new)
        new = []
        # print(new)