filename = "a.in"
outfilename = "output.txt"

def solve(f):
    n = int(f.readline())
    a = 0
    b = 0
    arr = map(int, f.readline().split(" "))
    for i in range(n - 1):
        a += max(0, arr[i] - arr[i+1])

    max_rate = 0
    for i in range(n-1):
        max_rate = max(max_rate, arr[i] - arr[i+1])

    for i in range(n-1):
        b += min(max_rate, arr[i])

    output = " ".join([str(a), str(b)])
    return output

def out(s, o):
    print s
    o.write("{}\n".format(s))

def main():
    f = open(filename)
    o = open(outfilename, 'w+')
    T = int(f.readline())
    t = 1
    while t <= T:
        output = solve(f)
        out("Case #{}: {}".format(t, output), o)
        t+=1

if __name__ == "__main__":
    main()
