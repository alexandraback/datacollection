#!/usr/bin/python

import sys, datetime, string

def solve(n, p):
    alph = string.uppercase
    l = [[p[k], k] for k in xrange(n)]
    l.sort()
    ret = []
    while l:
        if l[-1][0] > 1:
            if len(l) >= 2 and l[-1][0] == l[-2][0]:
                ret.append((l[-1][1], l[-2][1]))
                l[-1][0] -= 1
                l[-2][0] -= 1
            else:
                ret.append((l[-1][1],))
                l[-1][0] -= 1
        else:
            if len(l) % 2 == 1:
                ret.append((l.pop()[1],))
            else:
                a = l.pop()[1]
                b = l.pop()[1]
                ret.append((a, b))
        l.sort()
    return " ".join(map(lambda x : alph[x[0]] if len(x) == 1 else (alph[x[0]] + alph[x[1]]), ret))

def parse(input_file):
    n = int(input_file.readline().strip())
    p = map(int, input_file.readline().strip().split())
    return (n, p)

def main():
    start = datetime.datetime.now()
    input_file = open(sys.argv[1])
    output_file = open(sys.argv[2], "w") if len(sys.argv) > 2 else None
    print "Writing to %s" % sys.argv[2] if output_file else "No output file"
    test_cases = int(input_file.readline().strip())
    print "Test cases:",test_cases
    print '-----------------'
    for tc in xrange(1, test_cases + 1):
        output = "Case #%d: %s" % (tc, solve(*parse(input_file)))
        print output
        if output_file:
            output_file.write(output + "\n")
    print '-----------------'
    print "Written to %s" % sys.argv[2] if output_file else "No output file"
    print 'Elapsed time: %s' % (datetime.datetime.now() - start)
    input_file.close()
    if output_file:
        output_file.close()

if __name__ == "__main__":
    main()
