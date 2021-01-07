#!/usr/bin/python3
'''
Calculates the minimum number of operations to reach n.
'''


def minOperations(n):
    '''
    Copy pasta
    '''
    count = 0
    bucket = 0
    i = 1
    if (n < i):
        return 0
    while (n > i):
        if (i > bucket and n % i == 0):
            bucket = i
        else:
            i += bucket
        count += 1
    return count
    