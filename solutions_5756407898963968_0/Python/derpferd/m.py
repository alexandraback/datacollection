import sys

# fpIn = open("ex.in", "r")
# fpOut = open("ex.out", "w")
fpIn = open("small.in", "r")
fpOut = open("small.out", "w")


def raw_input():
    return fpIn.readline().strip()


class Print(object):
    def __init__(self, f):
        self.f = f

    def write(self, text):
        fpOut.write(text)
        self.f.write(text)

def do_test():
    line = raw_input()
    v = int(line)
    l1 = []
    l2 = []
    for i in range(4):
        line = raw_input()
        if i+1 == v:
            for num in line.split():
                l1.append(int(num))
    line = raw_input()
    v = int(line)
    for i in range(4):
        line = raw_input()
        if i+1 == v:
            for num in line.split():
                l2.append(int(num))

    same = []
    for x in l1:
        if x in l2:
            same.append(x)

    if len(same) == 0:
        return "Volunteer cheated!"
    elif len(same) == 1:
        return str(same[0])
    else:
        return "Bad magician!"


def main():
    line = raw_input()
    num_tests = int(line)
    for i in range(num_tests):
        print "Case #" + str(i+1) + ": " + do_test()

if __name__ == '__main__':
    if not isinstance(sys.stdout, Print):
        sys.stdout = Print(sys.stdout)
    main()

