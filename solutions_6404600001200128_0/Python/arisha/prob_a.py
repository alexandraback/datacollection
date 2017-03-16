infile = open('A-small-attempt0.in')
outfile = open('A-small-attempt0.out', 'w')

def method1(mushrooms):
    least = 0
    prev = mushrooms[0]
    for m in mushrooms:
        if prev > m:
            least += prev - m
        prev = m
    return least

def method2(mushrooms):
    least = 0
    max_diff = 0
    prev = mushrooms[0]
    for m in mushrooms:
        if prev > m and prev - m > max_diff:
            max_diff = prev - m
        prev = m
    for m in mushrooms[:-1]:
        if m < max_diff:
            least += m
        else:
            least += max_diff
    return least
        
cases = int(infile.readline().strip())
outformat = "Case #%d: %d %d"
for i in range(cases):
    infile.readline()
    mushrooms = map(int, infile.readline().strip().split())
    result = outformat % (i+1, method1(mushrooms), method2(mushrooms))
    outfile.write(result+'\n')

infile.close()
outfile.close()
