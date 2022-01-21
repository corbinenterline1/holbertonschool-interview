#!/usr/bin/python3
"""0x22 Prime Game"""


def isWinner(x, nums):
    """Prime game function."""
    if not nums or x < 1:
        return None
    n = max(nums)
    screen = [True for _ in range(max(n + 1, 2))]
    for i in range(2, int(pow(n, 0.5)) + 1):
        if not screen[i]:
            continue
        for j in range(i * i, n + 1, i):
            screen[j] = False
    screen[0] = screen[1] = False
    count = 0
    for i in range(len(screen)):
        if screen[i]:
            count += 1
        screen[i] = count
    p1 = 0
    for n in nums:
        p1 += screen[n] % 2 == 1
    if p1 * 2 == len(nums):
        return None
    if p1 * 2 > len(nums):
        return "Maria"
    return "Ben"
