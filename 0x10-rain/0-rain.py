#!/usr/bin/python3
"""
Given a list of non-negative integers representing the heights of walls with
unit width 1, as if viewing the cross-section of a relief map, calculate
how many square units of water will be retained after it rains.
Ends of list (before index 0 and after index walls[-1] are not walls.
"""


def rain(walls):
    """Calculates total amount of rain based on retainer walls."""
    totalrain = 0
    basin = 0
    retwall = 0

    if (len(walls) <= 2):
            return (0)

    for i in range(len(walls)):
        if walls[i] < retwall:
            basin += retwall - walls[i]
        else:
            totalrain += basin
            basin = 0
            retwall = walls[i]

    basin = 0
    retwall = 0
    if walls[0] == max(walls) and walls[len(walls) - 1] == max(walls):
        return (totalrain)

    walls.reverse()
    for i in range(len(walls)):
        if walls[i] < retwall:
            basin += retwall - walls[i]
        else:
            totalrain += basin
            basin = 0
            retwall = walls[i]

    return (totalrain)
