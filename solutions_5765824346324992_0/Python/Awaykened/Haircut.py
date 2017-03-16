import sys
sys.stdin = open("Input.txt","r")
sys.stdout = open("Output.txt","w")
t = int(raw_input())
for test in range(1,t+1):
    b,n = map(int,raw_input().split())
    barbers = map(int,raw_input().split())
    go = []
    tot = 0
    curr= [0 for i in range(b)]
    while 1:
        mini = 999999999
        best = -1
        for barber in range(b):
            if curr[barber]<mini:
                best = barber
                mini = curr[barber]
        curr[best]+=barbers[best]
        go.append(best)
        if min(curr) == max(curr):
            break
    print "Case #"+str(test)+":",go[n%(len(go))-1]+1
sys.stdout.close()
