infile = open("A-small-attempt0.in","r")
outfile = open("A-small-attempt0.out","w")

T = int(infile.readline())

def solve1(number, mushrooms):
    count = 0
    for i in range(number-1):
        if mushrooms[i] > mushrooms[i+1]:
            count += (mushrooms[i] - mushrooms[1+i])
    return count

def solve2(number, mushrooms):
    minimum = 0
    for i in range(number-1):
        if minimum < (mushrooms[i] - mushrooms[1+i]):
            minimum = (mushrooms[i] - mushrooms[1+i])
    count = 0
    for i in range(number-1):
        temp = mushrooms[i] > mushrooms[i+1]
        if mushrooms[i] < minimum:
            count += mushrooms[i]
        else:
            count += minimum
    return count

for case in range(T):
    time = int(infile.readline())
    times = infile.readline().split()
    for i in range(time):
        times[i] = int(times[i])
    solution1 = solve1(time, times)
    solution2 = solve2(time, times)
    outfile.write("Case #{0}: {1} {2}\n".format(case+1, solution1, solution2))

infile.close()
outfile.close()
