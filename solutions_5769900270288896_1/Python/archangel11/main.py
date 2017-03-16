filename = "a.in"
outfilename = "output.txt"

def solve(f):
    arr = map(int, f.readline().split())
    r = arr[0]
    c = arr[1]
    n = arr[2]

    noise = 0

    if n <= (r*c+1)/2:
        noise = 0
    elif r == 1:
        noise = (n - (r*c + 1)/2) * 2
        if c % 2 == 0:
            noise -= 1
    elif c == 1:
        noise = (n - (r*c + 1)/2) * 2
        if r % 2 == 0:
            noise -= 1
    elif r % 2 == 0 or c % 2 == 0:
        n = n - r * c / 2
        perimeterCells = 2 * (r + c) - 4
        perimeterCells /= 2
        if n > 0:
            if n <= 2:
                noise += 2 * n
            else:
                n -= 2
                noise += 4
                if n <= perimeterCells - 2:
                    noise += 3 * n
                else:
                    n = n - perimeterCells + 2
                    noise = noise + 3 * (perimeterCells - 2)
                    noise += 4 * n
    else:
        if n > (r * c + 1) / 2:
            extra1 = n - (r * c) / 2
            extra2 = extra1 - 1
            noise1 = 0
            noise2 = 0
            perimeterCells = r + c - 2
            if extra1 <= 4:
                noise1 += 2 * extra1
            else:
                extra1 -= 4
                noise1 += 8
                if extra1 <= perimeterCells - 4:
                    noise1 += (extra1 * 3)
                else:
                    extra1 -= (perimeterCells - 4)
                    noise1 += (3 * (perimeterCells - 4))
                    noise1 += (4 * extra1)
            if extra2 <= perimeterCells:
                noise2 += 3 * extra2
            else:
                extra2 -= perimeterCells
                noise2 += (3 * perimeterCells)
                noise2 += (4 * extra2)
            noise = min(noise1, noise2)


    output = noise
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
