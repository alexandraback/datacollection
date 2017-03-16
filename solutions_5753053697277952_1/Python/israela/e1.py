import sys

def find_max(a):
    m = -1
    mi = -1
    for i in xrange(len(a)):
        if a[i] > m:
            m = a[i]
            mi = i
    return mi

def solve(a):
    letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    res = []

    while a.count(0) != len(a):
        if a.count(1) == 3 and a.count(0) == len(a) - 3:
            i = find_max(a)
            res.append(letters[i])
            a[i] -= 1
        else:
            i = find_max(a)
            s = letters[i]
            a[i] -= 1
            i = find_max(a)
            s += letters[i]
            a[i] -= 1
            res.append(s)
    return " ".join(res)

input_file = open(sys.argv[1], "r")
output_file = open(sys.argv[2], "w")

T = int(input_file.readline().strip())
results = []
for i in xrange(T):
    n = int(input_file.readline().strip())
    a = [int(k) for k in input_file.readline().strip().split(' ')]
    results.append(solve(a))

for i in xrange(T):
    output_file.write("Case #{0}: {1}\n".format(i+1, results[i]))

input_file.close()
output_file.close()