#!/usr/bin/python
import sys, math

#solve case function
def solve_case(strings, case_number):
    str_lists = []
    list_ites = []
    for str in strings:
        str_lists .append(list(str))
        list_ites.append(0)

    max_length = max(map(len, str_lists))
    count = 0
    prev = "X"
    while max_length > max(list_ites):
        chk = []
        for index in range(0, len(str_lists)):
            if list_ites[index] < len(str_lists[index]):
                chk.append(str_lists[index][list_ites[index]])
            else:
                chk.append(str_lists[index][-1])

        chk_set = list(set(chk))
        if len(chk_set) == 1:
            list_ites = [x + 1 for x in list_ites]
            prev = chk[0]
            continue
        if len(chk_set) > 2:
            count = -1
            break
        min_c = chk_set[0]
        max_c = chk_set[1]
        if chk.count(chk_set[0]) > chk.count(chk_set[1]):
            min_c = chk_set[1]
            max_c = chk_set[0]

        if max_c == prev:
            count += chk.count(min_c)
            for index in range(0, len(chk)):
                if chk[index] != min_c:
                    list_ites[index] += 1
            continue

        if min_c == prev:
            count += chk.count(min_c)
            for index in range(0, len(chk)):
                if chk[index] == min_c:
                    list_ites[index] += 1
            continue
        count = -1
        break

    if count < 0:
        print "Case #%d: Fegla Won" % case_number
    else:
        print "Case #%d: %d" % (case_number, count)

#main
r = sys.stdin

if len(sys.argv) > 1:
    r = open(sys.argv[1], 'r')

total_cases = r.readline()
for case_number in range(1, int(total_cases) + 1):
    n = int(r.readline())
    strings = []
    for i in range(0, n):
        strings.append(r.readline())
    solve_case(strings, case_number)