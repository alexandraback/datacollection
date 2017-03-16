import fileinput
import logging
import sys

logging.basicConfig(stream=sys.stderr,level=logging.ERROR)


nTest = 0
line_no = 0
instances = []

first_instance_line = True

for line in fileinput.input():
    if line_no == 0:
        nTest = int(line)
        logging.debug("%d" % nTest)
    else:
        a = line.split()
        (R,C,N) = (int(a[0]),int(a[1]),int(a[2]))
        instances.append((R,C,N))
    line_no+=1


memo_pvalue = {}

def pvalue(pattern):
    if pattern in memo_pvalue:
        return memo_pvalue[pattern]
    val = 0
    num = pattern[1]
    for i in xrange(1,pattern[0]):
        if ((num/(2**i))%2) == 1 and ((num/(2**(i-1)))%2) == 1:
            val += 1
    memo_pvalue[pattern] = val
    logging.debug("pvalue (%d,%d) %d " % (pattern[0], pattern[1],val))
    return val

counts = {}

def count(pattern):
    if pattern in counts:
        return counts[pattern]
    val = 0
    num = pattern[1]
    for i in xrange(0,pattern[0]):
        if (num/(2**i)%2) == 1:
            val += 1
    counts[pattern] = val
    logging.debug("counts (%d,%d) %d " % (pattern[0], pattern[1],val))
    return val


table = {}

big = 10000

patterns_for_i = {}

interact_table = {}

def interaction(p1,p2):
    assert(p1[0] == p2[0])
    if (p1,p2) in interact_table:
        return interact_table[(p1,p2)]
    else:
        val = 0
        for i in xrange(0,p1[0]):
            n1 = p1[1]
            n2 = p2[1]
            if (n1/(2**i)%2) == 1 and ((n2/2**i)%2) == 1:
                val +=1
        interact_table[(p1,p2)] = val
        logging.debug("interaction (%d,%d) (%d,%d) %d " % (p1[0], p1[1], p2[0],p2[1],val))
        return val

def dyn_prog(i,k,pattern,patterns):
    this_value = pvalue(pattern)
    if (i,k,pattern) in table:
        return table[(i,k,pattern)]    
    if (i == 1):
        if (k == count(pattern)):
            table[(i,k,pattern)] = this_value
            return this_value
        else:
            table[(i,k,pattern)] = 10000
            return 10000
    else:
        val = 10000
        logging.debug("pattern")
        logging.debug(pattern)
        for p2 in patterns:
            j = count(pattern)
            r = dyn_prog(i-1,k-j,p2,patterns) + interaction(pattern,p2)
            if r+this_value < val:
                val = r+this_value
        logging.debug("val %d %d %d" % (i,k, val))
        table[(i,k,pattern)] = val
        return val

def gen_patterns(k):
    if k in patterns_for_i:
        return patterns_for_i[k]
    patterns = []
    for i in xrange(0,2**k):
        patterns.append((k,i))
    patterns_for_i[k] = patterns
    logging.debug("patterns %d" % k)
    logging.debug(patterns)
    return patterns
    
def instance(inst):
    (R,C,N) = inst
    if R < C:
        tmp = C
        C = R
        R = tmp
    patterns = gen_patterns(C)
    return dyn_prog(R+1,N,(C,0), patterns)

out_line_no = 1
for x in instances:
    solution = instance(x)
    print "Case #%d: %d" % (out_line_no, instance(x))
    out_line_no+=1


