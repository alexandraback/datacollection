def parse(input_file, output_file):
    with open(input_file) as f:
        n_cases = int(f.readline().split()[0])
        data = dict()
        lengths = [0] * n_cases
        for i in range(n_cases):
            lengths[i] = int(f.readline().split()[0])
            data[i] = [int(x) for x in f.readline().split()]
    f = open(output_file, 'w')
    for i in range(n_cases):
        ans1 = solve1(lengths[i], data[i])
        ans2 = solve2(lengths[i], data[i])
        line = "Case #"+str(i+1)+": "+str(ans1)+" "+str(ans2)
        print(line)
        f.write(line+'\n')
    return


def solve1(length, seq):
    pre = seq[0]
    sum = 0
    for i in seq[1:]:
        #seqi = seq[i]
        if i<pre:
            sum += pre-i
        pre = i
    return sum

def solve2(length, seq):
    diff = [y-x for (x,y) in zip(seq[1:], seq[:-1])]
    uniform = [max(diff)] * (length-1)
    tosum = list(map(min, zip(uniform, seq[:-1])))
    return sum(tosum)


input_file = "./2015-1A/test.txt"
input_file = "./2015-1A/A-small-attempt0.in"
input_file = "./2015-1A/A-large.in"
output_file = "./2015-1A/A-large.out"
parse(input_file, output_file)
