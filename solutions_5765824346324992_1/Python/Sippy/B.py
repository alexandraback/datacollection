def finished_count(Ms, t):
    num = 0
    free_list = []
    count = 1
    for m in Ms:
        num += t/m
        if t%m !=0: num += 1
        else: free_list.append(count)
        count += 1
    return num, free_list


def calc(file):
    B, N = map(int, file.readline().split())
    Ms = map(int, file.readline().split())
    tmin = 0
    tmax = 1000000000000000
    while True:
        t = (tmin + tmax)/2
        num, free_list = finished_count(Ms, t)
        if num >= N:
            tmax = t
        else :
            if num+len(free_list) < N:
                tmin = t
            else:
                diff = N - num
                return free_list[diff-1]


def main():
    file = open("input.txt")
    fl_o = open("output.txt", 'w')
    T = int(file.readline())
    for t in range(T):
        ans = calc(file)
        fl_o.write("Case #" + str(t+1) + ": " + str(ans) + "\n")
    fl_o.close()

main()