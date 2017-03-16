import sys
import string
import fractions

fname = 'A'

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


def process(fp):
    N = int(fp.readline())
    results = fp.readline().split()
    mush = map(int, results)
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
