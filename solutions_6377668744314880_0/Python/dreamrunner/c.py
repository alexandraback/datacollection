def relation(a, b):
    return a[0]*b[1] - a[1]*b[0]

# print(relation([1,1], [2,2]))
# print(relation([1,1], [1,2]))
# print(relation([1,1], [2, 1]))


test = int(input())

for t in range(1, test+1):
    print("Case #" + str(t) + ":")
    n = int(input())
    p = list()
    for i in range(n):
        p.append([int(j) for j in input().split(" ")])
    # print(p)
    if n <= 3:
        for i in range(n):
            print(0)
        continue

    for i in range(n):
        min_cut = n
        # Qiu i
        for j in range(n):
            if i == j:
                continue
            cur_left = 0
            cur_right = 0
            for k in range(n):
                if k == i:
                    continue
                if k == j:
                    continue
                # print("i-k", p[k][0] - p[i][0], p[k][1] - p[i][0])
                r = relation([p[k][0] - p[i][0], p[k][1] - p[i][1]], [p[j][0] - p[i][0], p[j][1] - p[i][1]])
                if r > 0:
                    cur_left += 1
                elif r < 0:
                    cur_right += 1
            cur_cut = min(cur_left, cur_right)
            # print(i, j, cur_left, cur_right)
            min_cut = min(cur_right, min_cut)
        print(min_cut)
