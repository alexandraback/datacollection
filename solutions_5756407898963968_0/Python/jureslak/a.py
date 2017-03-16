for tn in range(int(input())):
    n = int(input())
    s = [input().split() for i in range(4)]
    m = int(input())
    t = [input().split() for i in range(4)]
    g = set(s[n-1]) & set(t[m-1])
    print("Case #{}: ".format(tn+1),end='')
    if len(g) == 0:
        print("Volunteer cheated!")
    elif len(g) == 1:
        print(g.pop())
    else:
        print("Bad magician!")

