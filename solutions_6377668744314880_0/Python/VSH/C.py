fin = open("input.txt", 'r')
fout = open("output.txt", 'w')
t = int(fin.readline())

def rotate(A,B,C):
  return (B[0]-A[0])*(C[1]-B[1])-(B[1]-A[1])*(C[0]-B[0])

masks = []

def makemasks(curr, n):
    if len(curr) == n:
        global masks
        masks.append(curr)
        return
    makemasks(curr + [1], n)
    makemasks(curr + [0], n)


def grahamscan(A):
    if len(A) <= 3:
        return [i for i in range(len(A))]
    n = len(A)
    P = list(range(n))
    for i in range(1,n):
        if A[P[i]][0]<A[P[0]][0]:
            P[i], P[0] = P[0], P[i]
    for i in range(2,n):
        j = i
        while j>1 and (rotate(A[P[0]],A[P[j-1]],A[P[j]])<0):
            P[j], P[j-1] = P[j-1], P[j]
            j -= 1
    S = [P[0],P[1]]
    for i in range(2,n):
        while rotate(A[S[-2]],A[S[-1]],A[P[i]])<0:
            del S[-1]
        S.append(P[i])
    return S

def checkonbound(x1, x2, q):
    if rotate(x1, q, x2) != 0 and x1 != q and x1 != x2 and q != x2:
        return False
    x1min = min(x1[0], x2[0])
    x1max = max(x1[0], x2[0])
    y1min = min(x1[1], x2[1])
    y1max = max(x1[1], x2[1])
    if q[0] < x1min or q[0] > x1max:
        print(22222)
        return False
    if q[1] < y1min or q[1] > y1max:
        print(333333)
        return False
    return True

def checkforbound(q, n, A, mask):
    k = []
    q_ = 0
    for i in range(n):
        if mask[i] == 1:
            q_ += 1
    if q_ <= 3:
        return True
    for i in range(n):
        if mask[i] == 1:
            k.append(A[i])
    S = grahamscan(k)
    vert = A[q]
    onbound = False
    for i in range(len(S)):
        if i != len(S) - 1:
            onBound = checkonbound(A[S[i]], A[S[i + 1]], A[q])
        else:
            onBound = checkonbound(A[S[i]], A[S[0]], A[q])
    return onbound


def processp(q, n, A):
    global masks
    for i in range(len(masks)):
        if checkforbound(q, n, a, masks[i]):
            m = 0
            for j in range(n):
                if masks[i][j] == 0:
                    m += 1
            return m


def process(n, A):
    q = []
    for i in range(n):
        q.append(processp(i, n, A))
    return q

for test in range(1, t + 1):
    print(test)
    n = int(fin.readline())
    masks = []
    makemasks([], n)
    a = []
    for i in range(n):
        x, y = map(int, fin.readline().split())
        a.append([x, y])
    if n >= 4:
        l = process(n, a)
    else:
        l = [0 for i in range(n)]
    fout.write("Case #" + str(test) + ':\n')
    for elem in l:
        fout.write(str(elem) + '\n')
fin.close()
fout.close()
a = [0, 0]
b = [2, 0]
c = [2, 2]
d = [0, 2]
e = [1, 1]
print(rotate(c, e, d))
print(rotate(c, e, b))
