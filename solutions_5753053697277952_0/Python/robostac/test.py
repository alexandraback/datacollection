import math
import string
def num_to_let(x):
    if x == " ":
        return x
    return string.ascii_uppercase[x-1]

def solve(N):
    max = -1
    evac = []
    while max != 0:
        print(N)
        max = 0
        valid = []
        for i in range(0,len(N)):
            if (N[i] == max):
                valid.append(i)
            if (N[i] > max):
                max = N[i]
                valid = [i]
        if (max > 0):
            #print(valid,max)
            evac.append(valid[0] + 1)
            N[valid[0]] -= 1
            if (len(valid) == 2):
                evac.append(valid[1] + 1)
                N[valid[1]] -= 1
            evac.append(" ")



    return "".join([num_to_let(x) for x in evac ])



def output_res(caseno,output, f):
    s = "Case #{}: {}".format(caseno,output)
    print(s)
    f.write(s + "\n")


f = open("input.txt")
f = open("A-small-attempt1.in")
outfile = open("output","w+")
T = int(f.readline())
for case in range(1, T + 1):
    f.readline()
    N = [int(x) for x in f.readline().split()]
    output_res(case, solve(N),outfile)

