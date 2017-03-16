#!/usr/bin/python2
# -*- coding: utf8 -*-
# Google Code Jam 2016 - 1C - Problem A - Mateusz Kurek


def empty(l):
    return all([x <= 0 for x in l])


def get_maxes(l):
    m1, m2 = 0, 0
    for i, v in enumerate(l):
        if v < 0:
            continue
        if v > l[m1]:
            m2 = m1
            m1 = i
        elif v > l[m2] or (v == l[m2] and m1 == m2):
            m2 = i
    return m1, m2


def get_letter(i):
    return chr(i + ord('A'))


def tree1(l):
    zero, one = 0, 0
    for x in l:
        if x == 0:
            zero += 1
        elif x == 1:
            one += 1
    return one == 3 and zero + one == len(l)


def solve():
    n = int(raw_input())
    parties = []
    result = []
    # for i in range(n):
    #     pi = int(raw_input())
    #     parties.append(pi)
    parties = map(int, raw_input().split())
    # print(parties, result)

    while not empty(parties):
        m1, m2 = get_maxes(parties)
        if m1 == m2:
            result.append(get_letter(m1))
            parties[m1] -= 1
            if parties[m1] > 1 or (parties[m1] == 1 and len(parties) != 2):
                result.append(get_letter(m1))
                parties[m1] -= 1
        else:
            l1, l2 = '', ''
            special = tree1(parties)
            if parties[m1] > 0:
                l1 = get_letter(m1)
                parties[m1] -= 1
            if not special and parties[m2] > 0:
                l2 = get_letter(m2)
                parties[m2] -= 1
            result.append(l1 + l2)
        # print(parties, result)

    return ' '.join(result)


def main():
    t = int(raw_input())
    for i in range(1, t + 1):
        result = solve()
        print('Case #{}: {}'.format(i, result))

if __name__ == '__main__':
    main()
