def calc(file):
    n = int(file.readline())
    ms = map(int, file.readline().split())
    first = 0
    second = 0
    mxx = 0
    for i in range(1, n):
        diff = ms[i-1] - ms[i]
        if diff > 0: first += diff
        if diff > mxx: mxx = diff
    for i in range(0, n-1):
        eat = ms[i]
        if eat > mxx: eat = mxx
        second += eat

    return str(first) + " " + str(second)


def main():
    file = open("input.txt")
    fl_o = open("output.txt", 'w')
    T = int(file.readline())
    for t in range(T):
        ans = calc(file)
        fl_o.write("Case #" + str(t+1) + ": " + str(ans) + "\n")
    fl_o.close()

main()