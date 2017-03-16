#!/usr/bin/python3
from collections import defaultdict
import sys

def getCost(index, structures):
    l_count = sys.maxsize

    counts = defaultdict(int)

    for structure in structures:
        counts[structure[index]] += 1

    for k1, v1 in counts.items():
        count = 0
        for k2, v2 in counts.items():
            count += abs(k1-k2)*v2
        if count < l_count:
            l_count = count

    return l_count

def main():
    infile = open(sys.argv[1], "r")
    outfile = open(sys.argv[1][:-2] + "out", "w")

    for case in range(1, int(infile.readline())+1):
        strings = [infile.readline().strip() for i in range(int(infile.readline()))]

        order = strings[0][0]
        for char in strings[0]:
            if char != order[-1]:
                order+=char

        structures = []

        possible = True

        for string in strings:
            prev = ""
            structure = []
            for char in string:
                if char == prev:
                    structure[-1] +=1
                else:
                    if len(structure) >= len(order) or order[len(structure)] != char:
                        possible = False
                    structure.append(1)
                    prev = char
            if prev != order[-1]:
                possible = False

            structures.append(structure)

        if possible:
            cost = 0
            for i in range(len(order)):
                cost += getCost(i, structures)

            output = cost
        else:
            output = "Fegla Won"


        print("Case #{0}: {1}".format(case, output), file=outfile)

if __name__ == "__main__":
        main()
