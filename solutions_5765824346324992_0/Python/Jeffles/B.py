import sys
import string
import fractions

fname = 'B'

output_format = 'single'
scale_op = input('Data Scale? 0 - sample,  1 - small,  2 - large: ')
scale = ''
if scale_op == 0:
    scale = 'small-practice'
elif scale_op == 1:
    scale = 'small'
elif scale_op == 2:
    scale = 'large'
else:
    sys.exit(0)

input_file = open(fname + '-' + scale + '.in', 'r')
output_file = open(fname + '-' + scale + '.out', 'w')

def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)

def lcmm(*args):
    """Return lcm of args."""
    return reduce(lcm, args)

def process(fp):
    (B, N) = fp.readline().split()
    B = int(B)
    N = int(N)
    results = fp.readline().split()

    M = map(int, results)
    # my_lcm = reduce(lcm, M)  # Find least common multiple, rest are repeats
    # print "lcm", my_lcm
    # if my_lcm * len(M) < N:
    #    N = N % len(M) * my_lcm
    #N = N % my_lcm
    #if N < B:
    #    return N
    #print B, N, M, my_lcm
    print B, N, M
    if N < B:
        return N + 1

    N2 = N -len(M)
    M2 = M[:]  # Use M2 to decrement M as the master
    M3 = range(len(M2))  # Use to build answer for longer solutions
    #print M3
    while True:
        M2 = map(lambda x : x - min(M2), M2)
        if max(M2) == 0:
            break
        for elem in range(len(M2)):
            if M2[elem] == 0:
                N2 -=1
                if N2 == 0:
                    return elem + 1
                M2[elem] = M[elem]
                M3.append(elem)

    N = N % (len(M3))
    #print "Length",  N, M3, N-1,  M3[N-1]
    #print N, M3[N-1] +1
    return M3[N-1]+1

    return "fail"
    m0 = mush[0]
    max_diff=0
    case_1=0
    for mu in mush[1:]:
        if mu < m0:
            diff = m0 - mu
            case_1 += diff
            if diff > max_diff:
                max_diff = diff
        m0 = mu
    #print N, mush, max_diff
    case_2 = 0
    for mu in mush[:-1]:
        #print "mu", mu, min(max_diff, mu)
        case_2 += min(max_diff, mu)

    return "{0} {1}".format(case_1, case_2)
#    (a, b) = fp.readline().rstrip().split('/')


def format_output(fp, i, result):
    if output_format == 'single':
        fp.write('Case #%d: %s\n' % (i, result))
    elif output_format == 'multiple':
        fp.write('Case #%d:\n' % (i,))
        for r in result:
            fp.write('%s\n' % r)
    else:
        print 'No output format.'
    print('Case #%d: %s' % (i, result))

T = int(input_file.readline().rstrip('\n'))
for i in range(1, T+1):
    result = process(input_file)
    format_output(output_file, i, result)

input_file.close()
output_file.close()

print('Done.')
