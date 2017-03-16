import itertools


def is_right((p, q, r)):
    assert p != q and q != r and p != r
    sum1 = q[0]*r[1] + p[0]*q[1] + r[0]*p[1]
    sum2 = q[0]*p[1] + r[0]*q[1] + p[0]*r[1]
    if sum1 - sum2 <= 0: return 1
    else: return 0


def calc_convex(P):
    points = map(None, P)
    points.sort()

    upper = [points[0], points[1]]
    for p in points[2:]:
        upper.append(p)
        while len(upper) > 2 and not is_right(upper[-3:]):
            del upper[-2]

    points.reverse()
    lower = [points[0], points[1]]
    for p in points[2:]:
        lower.append(p)
        while len(lower) > 2 and not is_right(lower[-3:]):
            del lower[-2]

    del lower[0]
    del lower[-1]

    return tuple(upper + lower)

def calc(file):
    N = int(file.readline())
    cor = []
    for _ in range(N):
        x, y = map(int, file.readline().split())
        cor.append((x,y))
    ans_map = dict()
    for i in cor:
        ans_map[i] = max(N-3, 0)
    for r in range(4, N+1):
        subset_cor = itertools.combinations(cor, r)
        for each_cor in subset_cor:
            cor_list = calc_convex(each_cor)
            for i in cor_list:
                if ans_map[i] > N-r: ans_map[i] = N-r
    ans_list = []
    for i in cor:
        ans = ans_map[i]
        ans_list.append(ans)
    return ans_list

def main():
    file = open("input.txt")
    fl_o = open("output.txt", 'w')
    T = int(file.readline())
    for t in range(T):
        ans_list = calc(file)
        fl_o.write("Case #" + str(t+1) + ":\n")
        for ans in ans_list:
            fl_o.write(str(ans) + "\n")
    fl_o.close()

main()