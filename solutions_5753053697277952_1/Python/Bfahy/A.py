#!/usr/bin/env python3
import argparse
import math
import logging



def read_input():
    f = open(args.inputfile)
    T = int(f.readline())
    for i in range(T):
        N = int(f.readline())
        Ps = list(map(int, f.readline().split()))
        yield Ps


def output(n, s):
    outstring = "Case #{}: {}\n".format(n, s)
    print(outstring, end="")
    outfile.write(outstring)


def remove(counts):

    M = max(counts)
    max_occurs = counts.count(M)
    logging.debug("{} occurs {} times in {}".format(M, max_occurs, counts))
    assert(M > 0)

    if max_occurs == 1 or max_occurs == 3:
        r1 = counts.index(M)
        counts[r1] -= 1
        print(r1)
        return r1, -1, counts
        exit(-1)
    if max_occurs > 1:
        r1 = counts.index(M)
        counts[r1] -= 1
        r2 = counts.index(M)
        counts[r2] -= 1
        print(r1)
        print(r2)
        return r1, r2, counts
        exit(-1)

    return r1, r2, counts

def main():
    for n, case in enumerate(read_input(), start=1):
        logging.info(case)

        revalphabet = list("ZYXWVUTSRQPONMLKJIHGFEDCBA")
        alphabet =  "ABCDEFGHIJKLMNOPQRSTUVWXYZ "

        initial = ""

        counts = case

        # for i in case:
        #     c = alphabet.pop()
        #     initial += c*i

        evacplan = ""

        while(max(counts) > 0):
            print("wtf", max(counts), counts)
            r1, r2, counts = remove(counts)
            print(r1, r2, counts)
            print(alphabet[r1], alphabet[r2], counts)
            if r2 > 0 :
                evacplan += alphabet[r1] + alphabet[r2] + " "
            else:
                evacplan += alphabet[r1] + " "
            logging.debug("evac plan is not {}".format(evacplan))
            #exit(-1)


        output(n, evacplan)




if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="google code jam 1a 2016 A")
    parser.add_argument("inputfile", type=str, help="input file")
    parser.add_argument("-v", "--verbose", action="store_true",
                        help="increase output verbosity")
    args = parser.parse_args()
    outfile = open(args.inputfile + ".out", "w")
    if args.verbose:
        logging.basicConfig(format='%(levelname)s: %(message)s', level=logging.DEBUG)
        logging.debug("Verbose debuging mode activated")
    else:
        logging.basicConfig(format='%(levelname)s: %(message)s', level=logging.INFO)
    main()
