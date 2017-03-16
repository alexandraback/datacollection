import sys
from collections import defaultdict
import itertools


def print_solutions(filename):
    content = open(filename).read().strip().split('\n')
    test_case_count = int(content[0])
    i = 1
    tk = 1
    parties = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    while tk <= test_case_count:
        parties_count = content[i]
        senators_list = [int(c) for c in content[i+1].split(' ')]
        all_count = sum(senators_list)
        senators_list = zip(parties, [int(c) for c in content[i+1].split(' ')])
        senators_list = [list(p) for p in senators_list]
        senators_list.sort(key=lambda s: s[1], reverse=True)
        if (all_count % 2):
            plan = [senators_list[0][0]]
            senators_list[0][1] -= 1
            senators_list.sort(key=lambda s: s[1], reverse=True)
        else:
            plan = []
        while senators_list[0][1] > 0:
            if senators_list[0][1] - senators_list[1][1] > 1:
                plan.append(senators_list[0][0] * 2)
                senators_list[0][1] -= 2
            else:
                if senators_list[1][1]:
                    plan.append(senators_list[0][0] + senators_list[1][0])
                    senators_list[1][1] -= 1
                else:
                    plan.append(senators_list[0][0])

                senators_list[0][1] -= 1
            senators_list.sort(key=lambda s: s[1], reverse=True)



        print("Case #%s: %s" % (tk, " ".join(plan)))
        i += 2
        tk += 1

filename = sys.argv[1]
print_solutions(filename)
