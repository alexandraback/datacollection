#!/usr/bin/env python3
import argparse

parser = argparse.ArgumentParser(description="google code jam magician")
parser.add_argument("inputfile", type=str, help="input file")
args = parser.parse_args()
outfile = open(args.inputfile + ".out", "w")


def read_input():
    f = open(args.inputfile)
    T = int(f.readline())
    for i in range(T):
        guess1 = int(f.readline())
        grid1 = {}
        for i in range(1,5):
            grid1[i] = f.readline().split()
        guess2 = int(f.readline())
        grid2 = {}
        for i in range(1,5):
            grid2[i] = f.readline().split()
        yield guess1, grid1, guess2, grid2


def output(n, s):
    outstring = "Case #{}: {}\n".format(n, s)
    print(outstring, end="")
    outfile.write(outstring)


def main():
    for n, case in enumerate(read_input(), start=1):
        guess1, grid1, guess2, grid2 = case
        row1 = grid1[guess1]
        row2 = grid2[guess2]
        match = [i for i in row1 if i in row2]
        if len(match) == 1:
            answer = match[0]
        if len(match) > 1:
            answer = "Bad magician!"
        if len(match) < 1:
            answer = "Volunteer cheated!"

        output(n, answer)


if __name__ == "__main__":
    main()
