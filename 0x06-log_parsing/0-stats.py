#!/usr/bin/python3
"""Reads stdin line by line & computes metrics."""
import sys

if __name__ == "__main__":
    stat_codes = {'200': 0,
                  '301': 0,
                  '400': 0,
                  '401': 0,
                  '403': 0,
                  '404': 0,
                  '405': 0,
                  '500': 0}
    total_fs = 0

    def print_stats(stat_codes):
        """Prints file size, then count of any status codes"""
        print("File size: {}".format(total_fs))
        for key, value in sorted(stat_codes.items()):
            if value != 0:
                print("{}: {}".format(key, value))

    try:
        i = 0
        for line in sys.stdin:
            arg_list = line.split(" ")
            if len(arg_list) > 6:
                status = arg_list[-2]
                fs = arg_list[-1]
                if status in stat_codes:
                    i += 1
                    stat_codes[status] += 1
                total_fs += int(fs)
                if i % 10 == 0:
                    print_stats(stat_codes)
    except KeyboardInterrupt:
        print_stats(stat_codes)
