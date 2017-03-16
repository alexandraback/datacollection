import sys
import itertools

output_line = "Case #{X:d}: {answer}"

def find_largest(party_counts):
    largest = party_counts[0]
    party = 0
    for i, cnt in enumerate(party_counts):
        if largest <= cnt:
            largest = cnt
            party = i
            # party = chr(ord('A') - i)
    return party

if __name__ == "__main__":
    infile, outfile = sys.argv[1:]
    with open(infile, "r") as inhandle, open(outfile, "w") as outhandle:
        T = int(inhandle.readline())
        for t in range(T):
            N = int(inhandle.readline().strip())
            party_counts = list(map(int, inhandle.readline().strip().split()))

            evac = []

            while True:
                party = find_largest(party_counts)
                if party_counts[party] > 0:
                    party_counts[party] -= 1
                    evac.append(chr(ord('A') + party))
                else:
                    break

            egroup = []
            revac = list(reversed(evac))
            for f, s in itertools.zip_longest(itertools.islice(revac, 0, None, 2), itertools.islice(revac, 1, None, 2), fillvalue=''):
                egroup.append(s + f)
            ans = " ".join(reversed(egroup))


            outline = output_line.format(X=t + 1, answer=ans)
            print(outline, file=outhandle)
            print(outline)
