from fractions import gcd

def lcm(nums):
    return reduce(lambda x, y: (x*y)/gcd(x,y), nums, 1)

infile = open('B-small-attempt3.in')
outfile = open('B-small-attempt3.out', 'w')

cases = int(infile.readline().strip())
outformat = "Case #%d: %d"

for i in xrange(cases):
    barbers, people = map(int, infile.readline().strip().split())
    times = map(int, infile.readline().strip().split())
    m = times[:]
    if people <= barbers:
        result = outformat %(i+1, people)
        outfile.write(result + '\n')
        print result
        continue
    lcm_people = 0
    lcm_time = lcm(m)
    for m_k in m:
        lcm_people += lcm_time / m_k
    people = people % lcm_people
    if people <= barbers and people != 0:
        result = outformat %(i+1, people)
        outfile.write(result + '\n')
        print result
        continue
    if people == 0:
        people = lcm_people
    if people > barbers:
        people -= barbers
    while people != 0:
        least = min(m)
        for k in xrange(barbers):
            m[k] -= least
            if m[k] == 0:
                people -= 1
                m[k] = times[k]
                if people == 0:
                    result = outformat %(i+1, k+1)
                    outfile.write(result + '\n')
                    print result
                    break

infile.close()
outfile.close()
        
        
