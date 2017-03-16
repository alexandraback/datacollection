# python 2.7

import os, sys

class Input:
    def __init__(self, fp): self.fp = fp
    def m(self, n, t=str):  return [map(t, list(self.line())) for i in range(n)]
    def ms(self, n, t=str, sep=' '):  return [map(t, self.line().split(sep)) for i in range(n)]
    def line(self):  return self.fp.readline().strip()
    def lines(self, n): return [self.fp.readline().strip() for x in range(n)]
    def words(self): return self.line().split()
    def int(self):   return int(self.line())
    def ints(self):  return map(int, self.words())
    def float(self): return float(self.line())
    def floats(self):return map(float, self.words())
    def str(self):   return self.line()
    def types(self, *types): return [t(w) for t,w in zip(types, self.words())]

if __name__ == "__main__":
    fn = "test.txt" if len(sys.argv) <= 1 else sys.argv[1]
    f = Input(open(fn))
    fout = open(os.path.splitext(fn)[0] + ".out", "w")

    def write(o):
        sys.stdout.write(o)
        fout.write(o)

    def writeln():
        write("\n")

    def spacedWrite(o):
        write(o); write(" ")

    def case(t):
        write("Case #%d: "%t)

    def answer(t, ans):
        case(t)
        write("%s\n"%(ans))

    chars = [chr(x) for x in range(ord('A'), ord('Z') + 1)]
    def char(x):
        return chars[x]

    for T in range(f.int()):
        N = f.int()
        counts = f.ints()
        maxCount = max(counts)

        l = []
        for i in range(1, maxCount + 1)[::-1]:
            l.extend([j for (j, g) in enumerate(counts) if counts[j] >= i])

        case(T + 1)
        if len(l) % 2 == 1:
            spacedWrite(char(l[0]) + " ")
            l = l[1:]

        for i in range(0, len(l), 2):
            spacedWrite("".join(map(char, l[i:i+2])))
        writeln()
