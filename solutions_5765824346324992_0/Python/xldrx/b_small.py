#! /usr/bin/env python -u
# coding=utf-8

import sys

__author__ = 'xl'


def find_n(m_time):
    global M
    ans = 0
    for m in M:
        ans += m_time / m
    return ans


def find_next_time(m_time):
    global M
    ans = 1e6
    for i, m in enumerate(M):
        ans = min((m - m_time % m) % m, ans)
    return ans + m_time


if __name__ == "__main__":
    fp = open("B.in")
    sys.stdout = open("B.out", "w")
    # fp = sys.stdin

    T = int(fp.readline())
    for t in range(T):
        global M
        B, N = map(int, fp.readline().split())
        M = map(int, fp.readline().split())

        min_time = 0
        max_time = max(M) * N

        p_time = -1
        time = -2
        while p_time != time:
            p_time = time
            time = (max_time + min_time) / 2
            n = find_n(time)
            if n == N - 1:
                break
            elif n > N - 1:
                max_time = time
            else:
                min_time = time

        ans = -1
        index = N - n - 1
        while ans < 0:
            next_t = find_next_time(time)
            for i, m in enumerate(M):
                if next_t % m == 0:
                    if index == 0:
                        ans = i
                        break
                    else:
                        index -= 1
            time = next_t + 1

        print "Case #%s: %s" % (t + 1, ans + 1)