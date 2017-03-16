#!/usr/bin/env python3
# -*- coding: utf-8 -*-


import os
import sys
from functools import wraps, lru_cache


def io_wrapper(func):
    @wraps(func)
    def _func(in_file=None, out_file=None, lines_per_case=1):
        in_buffers = []
        if in_file is None:
            while True:
                try:
                    s = input()
                    if s.strip():
                        in_buffers.append(s.strip())
                except:
                    break
        else:
            with open(in_file, 'r') as f:
                in_buffers.extend([line.strip() for line in f.read().strip().splitlines()])
        total_case_nums = int(in_buffers[0])
        in_buffers = in_buffers[1:]
        # print(in_buffers)
        assert len(in_buffers) == total_case_nums * lines_per_case

        out_buffers = []
        for case_id in range(1, total_case_nums + 1):
            case_result_str = func('\n'.join(in_buffers[(case_id - 1) * lines_per_case: case_id * lines_per_case]))
            out_buffers.append('Case #{}: {}'.format(case_id, case_result_str))

        if out_file is not None and os.path.exists(out_file):
            print('Out file {} already exists!'.format(out_file), file=sys.stderr)
            out_buffers = None
        if out_file is None:
            print('\n'.join(out_buffers))
        else:
            with open(out_file, 'w') as f:
                f.write('\n'.join(out_buffers))

    return _func


@io_wrapper
@lru_cache(maxsize=None)
def solution(line_str):
    return "Answer Str"


@io_wrapper
def a(lines):
    n, *parties = map(int, lines.split())
    # print(n, parties)
    resutls = []
    total = sum(parties)
    import string
    names = string.ascii_uppercase[:n]
    numbers = dict(zip(names, parties))

    while total > 0:
        m = max(numbers, key=lambda c: numbers[c])
        resutls.append(m)
        total -= 1

        v = numbers[m]
        if v == 1:
            del numbers[m]
        else:
            numbers[m] = v - 1

    if len(resutls) % 2 == 1:
        resutls.insert(0, '')
    return ' '.join(a + b for a, b in zip(resutls[::2], resutls[1::2]))


def b():
    pass


def c():
    pass


if __name__ == '__main__':
    # solution()
    # a('A-sample.txt', lines_per_case=2)
    a('A-small-attempt0.in', lines_per_case=2)
    # a('A-large.in.txt', 'A-large.out.txt')

    pass
