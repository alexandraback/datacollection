#!/usr/bin/env python3

import sys

def evacuate(party_counts):
    parties = [unichr(c) for c in range(ord('A'), ord('Z')+1)]
    total = sum(party_counts)
    plan = []
    while total > 0:
        # could use updatable priority queue
        sorted_party_counts = sorted(enumerate(party_counts), key=lambda x: x[1])
        first = sorted_party_counts[-1]
        second = sorted_party_counts[-2]
        if len(party_counts) >= 3 and sorted_party_counts[-3][1] > 0:
            third = sorted_party_counts[-3]
        else:
            third = None

        if first[1] > second[1] and second[1] == 1:
            plan.append(parties[first[0]])
            party_counts[first[0]] -= 1
        elif third and first[1] == 1 and second[1] == 1:
            plan.append(parties[first[0]])
            party_counts[first[0]] -= 1
        else:
            plan.append(parties[first[0]] + parties[second[0]])
            party_counts[first[0]] -= 1
            party_counts[second[0]] -= 1
        total = sum(party_counts)
    return plan

def main():
    if len(sys.argv) < 2:
        print("Usage: evacuate.py <file>")
        exit()
    in_file = sys.argv[1]
    with open(in_file) as f:
        cases = int(f.readline())
        for i in range(0, cases):
            num_parties = int(f.readline().strip()) # Strip off the newline
            party_counts = [int(c) for c in f.readline().strip().split()]
            print("Case #%d: %s" % (i+1, " ".join([plan_step for plan_step in evacuate(party_counts)])))

##########

if __name__ == '__main__':
    main()
