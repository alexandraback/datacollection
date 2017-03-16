from repeater import solve

filename = "input.txt"
outfilename = "output.txt"

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
