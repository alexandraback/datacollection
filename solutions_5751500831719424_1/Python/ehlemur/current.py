
def unique(s):
    aux = s[0]
    for i in range(1, len(s)):
        if aux[-1] != s[i]:
            aux += s[i]
    return aux

def parse(s):
    aux = [[s[0], 1]]
    for i in range(1, len(s)):
        if aux[-1][0] == s[i]:
            aux[-1][1] += 1
        else:
            aux.append([s[i], 1])
    
    return [x[1]  for x in aux]

def transform(to, fr):
    global a

    cost = 0
    for i in range(len(a[to])):
        cost += abs(a[to][i] - a[fr][i])

    print("transform {} into {} with cost {}".format(a[fr], a[to], cost))

    return cost


T = int(input())

for tc in range(1, T + 1):
    N = int(input())
    a = [input() for i in range(N)]

    if len(set(unique(s)  for s in a)) != 1:
        cost = "Fegla Won"
    else:
        a = [parse(s)  for s in a]
        b = [sorted(x)  for x in zip(*a)]
        M = len(a[0])

        cost = 0 
        for i in range(M):
            # print(b[i], M)
            goal = b[i][N//2]
            for j in range(N):
                cost += abs(goal - a[j][i])

    print("Case #{}: {}".format(tc, cost))
