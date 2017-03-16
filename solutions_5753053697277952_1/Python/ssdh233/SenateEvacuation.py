# when input is too large
#f = open("txt","r")
#def input():
#   return f.readline().strip()

def item1(A):
    return A[1]

def solve(N, P):
    newP = []
    char = 65
    count = 0
    for p in P:
        count += p
        newP.append([chr(char),p])
        char += 1
    answer = ""
    while count > 0:
        maxP = max(newP, key=item1)
        temp = maxP[0]
        maxP[1] -= 1
        count -= 1
        if count != 2:
            maxP = max(newP, key=item1)
            temp += maxP[0]
            maxP[1] -= 1
            count -= 1
        answer += " " + temp
    return answer

T = int(input())
O = []

for index in range(T):
    N = int(input())
    P = map(int, input().split())
    O.append("Case #"+str(index+1)+":"+str(solve(N,P)))

for o in O:
    print(o)

