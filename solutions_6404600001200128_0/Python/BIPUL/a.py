def solve(a,max_eat):
    total = 0
    for i in range(len(a)-1):
        if a[i]>max_eat:
            total+=max_eat
        else:
            total+=a[i]
    return total


for t in range(int(input())):
    n = int(input())
    a = [int(s) for s in input().strip().split(" ")]
    total = 0
    max_eat = 0
    for i in range(len(a)-1):
        eat = a[i]-a[i+1]
        if eat > 0:
            total+=eat
            if eat > max_eat:
                max_eat = eat
    print("Case #{0}: {1} {2}".format(t+1,total,solve(a,max_eat)))
