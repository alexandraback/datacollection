import sys
from string import ascii_uppercase


class Jam(object):
    def __init__(self, filename):
        lines = open(filename + ".in").read().split("\n")[1:]  # remove the T
        fout = open(filename + ".out", "w")

        for t, line in enumerate(lines):
            if t % 2 == 0: continue
            result = self.solve(*(line.split()))
            print("Case #{}: {}".format((t + 1) // 2, result), file=fout)
    #        print("Case #{}: {}".format(t + 1, result))
        fout.close()

    def solve(self, *parties):
        out = []
        self.parties = list(map(int, parties))
        while sum(self.parties) > 0:
            if sum(self.parties) % 2:
                item = self.high()
                self.parties[item] -= 1
                out.append(ascii_uppercase[item])
            else:
                item = self.high()
                self.parties[item] -= 1
                item2 = self.high()
                self.parties[item2] -= 1
                out.append(ascii_uppercase[item] + ascii_uppercase[item2])

        return " ".join(out)

    def high(self):
        return max(range(len(self.parties)), key=self.parties.__getitem__)

if __name__ == '__main__':
    Jam(sys.argv[1])
