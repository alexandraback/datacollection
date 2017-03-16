import sys

if len(sys.argv) == 1:
    sys.stdin = open(__file__.replace('.py', '.in'))
else:
    sys.stdin = open(sys.argv[1])
    sys.stdout = open(sys.argv[1].replace('.in', '') + '.out', 'w')

def get_ints():
    return map(int, raw_input().split())

n_cases = input()

def noise_iter(rows, cols, num):
    for arrangement in xrange(1 << (rows * cols)):
        bits = '{:016b}'.format(arrangement)[::-1]
        if bits.count("1") != num:
            continue
        unhappiness = 0
        for r in range(rows):
            for c in range(cols):
                i = r * cols + c
                if bits[i] == '0':
                    continue
                if r > 0:
                    if bits[i - cols] == '1':
                        unhappiness += 1
                if c > 0:
                    if bits[i - 1] == '1':
                        unhappiness += 1
        yield unhappiness

for case in xrange(1, n_cases + 1):
    rows, cols, num = get_ints()

    print "Case #%d: %s" % (case, min(noise_iter(rows, cols, num)))
