#!/usr/bin/python

import sys


def main():
    data = sys.stdin
    nb = int(data.readline())
    for icase in xrange(nb):
        chosen_rows = []
        for ichosen in xrange(2):
            chosen = int(data.readline())
            for iline in xrange(4):
                if iline + 1 == chosen:
                    chosen_rows.append(map(int, data.readline().split()))
                else:
                    data.readline()
        dif = list(set(chosen_rows[0]) & set(chosen_rows[1]))
        res = ""
        if len(dif) == 1:
            res = str(dif[0])
        elif len(dif) == 0:
            res = "Volunteer cheated!"
        else:
            res = "Bad magician!"
        print "Case #%d: %s" % (icase + 1, res)


if __name__ == "__main__":
    main()
