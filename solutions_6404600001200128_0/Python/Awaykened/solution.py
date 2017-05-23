import sys
sys.stdin = open("Input.txt","r")
sys.stdout = open("Output.txt","w")
t = int(raw_input())
for test in range(1,t+1):
    n = int(raw_input())
    first = 0
    big = 0
    seq = map(int,raw_input().split())
    last = seq[0]
    second = 0
    for i in range(1,n):
        m = seq[i]
        if (m < last):
            first += last - m
            big = max(big,last-m)
        last = m
    for i in range(n-1):
        second += min(seq[i],big)
    print "Case #"+str(test)+":",first,second
    
sys.stdout.close()
