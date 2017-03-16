import math
import time
import sys

if __name__ == '__main__':
    
    # Start timer
    start = time.time()

    if len(sys.argv) != 3:
        print 'Usage: python problemA.py <input_file> <output_file>'
        sys.exit(0)
    
    input_file = sys.argv[1]
    output_file = sys.argv[2]

    lines = [line.strip() for line in open(input_file)]
    total = lines.pop(0)
    num_mr = lines[1:][::2]
    print num_mr

    results = []
    for i in range(len(num_mr)):
        case = num_mr[i]
        mrs = case.split()
        mrs = [int(t) for t in mrs]
        #print mrs
        sum_diff = 0
        max_diff = 0
        sum_max = 0
        for j in range(1, len(mrs)):
            if mrs[j]<mrs[j-1]:
                diff = mrs[j-1] - mrs[j]
                sum_diff += diff
                if diff > max_diff:
                    max_diff = diff
        #print sum_diff
        #print max_diff
        for j in range(len(mrs)-1):
            if mrs[j] <= max_diff:
                sum_max += mrs[j]
            else:
                sum_max += max_diff
        #print sum_max
        results.append((sum_diff, sum_max))
    print results

    # output
    f = open(output_file, 'w')
    for i in range(len(results)):
        f.write('Case #' + str(i+1) + ': ' + str(results[i][0]) + ' ' + str(results[i][1]) +'\n')
    f.close()

    # Stop timer
    end = time.time()
    print "Total time use:", end-start, "s"