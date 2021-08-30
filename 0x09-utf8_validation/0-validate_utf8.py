#!/usr/bin/python3
"""
UTF8 Validation by converting list of ints into arrays representing bytes
joined into a string with separators. This string is then attempted to be
decoded, with the UnicodeDecodeError returning False.
"""


def validUTF8(data):

    if type(data) is not list:
        return False
    byte_return = []
    for item in data:
        byte_test = item.to_bytes(2, 'big')
        try:
            byte_test.decode('utf-8')
        except UnicodeDecodeError:
            return False
        byte_test = None
    return True
