import sys

def input_parser(input_path):
    with open(input_path, 'r') as f:
        c = int(f.readline())
        for case in xrange(c):
            N = int(f.readline())
            m = map(int, f.readline().split())
            yield case, (N, m)

def get_output_path(input_path):
    return input_path[:-2] + "out"

def output(f, s):
    print s
    f.write(s + "\n")

def problem(N, m):
    m1 = 0
    rate = 0
    m2 = 0
    max_seen = 0
    prev = 0
    for ind, i in enumerate(m):
        if i < max_seen:
            m1 += max_seen - i
        max_seen = i
        if ind:
            rate = max(rate, prev - i)
        prev = i
    
    for i in m[:-1]:
        m2 += min(i, rate)
    return str(m1) + " " + str(m2)

def main():
    input_path = sys.argv[1]
    with open(get_output_path(input_path), 'w') as g:
        for case, data in input_parser(input_path):
            out = problem(*data)
            output(g, "Case #{}: {}".format(case+1, out))

if __name__ == "__main__":
    main()

