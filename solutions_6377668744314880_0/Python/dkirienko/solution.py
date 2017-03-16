class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b

class Vector:
    def __init__(self, a=0, b=0):
        if type(a) == Point and type(b) == Point:
            self.x = b.x - a.x
            self.y = b.y - a.y
        else:
            self.x = a
            self.y = b
    
    def dot(self, other):
        return self.x * other.x + self.y * other.y
    
    def cp(self, other):
        return self.x * other.y - self.y * other.x

def check2(P, S, A, B):
    SA = Vector(S, A)
    SB = Vector(S, B)
    if SA.cp(SB) != 0:
        # Точки не лежат на одной прямой, запускаем проверку
        inside = 0
        for i in range(len(P)):
            SP = Vector(S, P[i]);
            if SB.cp(SP) * SB.cp(SA) >= 0 and SA.cp(SP) * SA.cp(SB) >=0:
                inside += 1
        return len(P) - inside
    elif SA.dot(SB) < 0:
            pos = 0
            neg = 0
            for i in range(len(P)):
                SP = Vector(S, P[i]);
                if SA.cp(SP) > 0:
                    pos += 1
                elif SA.cp(SP) < 0:
                    neg += 1
            return min(pos, neg)
    else:
        return len(P) - 3


def check1(P, S):
    if len(P) <= 3:
        return 0
    # Лежат ли все точки на одной прямой?
    on_line = True
    for i in range(len(P)):
        for j in range(len(P)):
            if Vector(S, P[i]).cp(Vector(S, P[j])) != 0:
                on_line = False
    if on_line:
        return 0
    ans = len(P) - 3
    for i in range(len(P)):
        for j in range(i + 1, len(P)):
            if P[i] is not S and P[j] is not S:
                ans = min(ans, check2(P, S, P[i], P[j]))
    return ans


def solve(test_num):
    n = int(F.readline())
    P = list()
    for i in range(n):
        P.append(Point(*map(int, F.readline().split())))
    for i in range(n):
        print(check1(P, P[i]))

F = open("sample", "r")

for i in range(1, int(F.readline()) + 1):
    print("Case #", i, ": ", sep="")
    solve(i)

