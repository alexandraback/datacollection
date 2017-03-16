import sys
import heapq

def input_parser(input_path):
    with open(input_path, 'r') as f:
        c = int(f.readline())
        for case in xrange(c):
            B, N = map(int, f.readline().split())
            m = map(int, f.readline().split())
            yield case, (B, N, m)

def get_output_path(input_path):
    return input_path[:-2] + "out"

def output(f, s):
    print s
    f.write(s + "\n")

def gcd(a, b):
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    return a*b//gcd(a, b)

def lcmm(*args):
    return reduce(lcm, args)

def problem(B, N, m):
    rep = lcmm(*m)
    people_served_by_cycle = 0
    for br in m:
        people_served_by_cycle += rep/br
    out = N % people_served_by_cycle
    #print people_served_by_cycle
    #print out
    if out == 0:
        out = people_served_by_cycle

    h = [] 
    for b_id, t in enumerate(m):
        h.append((0, b_id))

    for i in range(out):
        #print h
        t, b_id = heapq.heappop(h)
        if i == out-1:
            return b_id + 1
        heapq.heappush(h, (t+m[b_id], b_id))

def main():
    input_path = sys.argv[1]
    with open(get_output_path(input_path), 'w') as g:
        for case, data in input_parser(input_path):
            out = problem(*data)
            output(g, "Case #{}: {}".format(case+1, out))

if __name__ == "__main__":
    main()

