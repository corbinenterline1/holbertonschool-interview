#!/usr/bin/python3
"""0x00 - Interview - Lockbox"""

def canUnlockAll(boxes):
    """Method to check if all boxes can be opened."""
    ll = list(range(1, len(boxes)))
    sl = len(ll)
    k = boxes[0]
    while ll:
        for key in k:
            if key in ll:
                ll.remove(key)
                k.extend(boxes[key])
        if len(ll) == sl:
                return False
        sl = len(ll)
    return True

if __name__ == '__main__':
    canUnlockAll(boxes)