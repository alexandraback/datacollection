import sys
import math

def check(a,b):
    #0-no 1-1 same 2-more than 1 same
    cnt=0
    num=0
    #print a,b
    for i in range(4):
        if a[i] in b:
            num=a[i]
            cnt+=1
    if cnt==1:
        return num
    elif cnt==0:
        return "Volunteer cheated!"
    else:
        return "Bad magician!"
    
#a=(map(int,sys.stdin.readline().split()))
myin=open("a.in")
sys.stdin=myin
myfile=open("newout.txt",mode='a')
sys.stdout=myfile
t=int(sys.stdin.readline())
for i in range(t):
    ch1=int(sys.stdin.readline())
    a=[]
    a.append(map(int,sys.stdin.readline().split()))
    a.append(map(int,sys.stdin.readline().split()))
    a.append(map(int,sys.stdin.readline().split()))
    a.append(map(int,sys.stdin.readline().split()))
    ch2=int(sys.stdin.readline())
    b=[]
    b.append(map(int,sys.stdin.readline().split()))
    b.append(map(int,sys.stdin.readline().split()))
    b.append(map(int,sys.stdin.readline().split()))
    b.append(map(int,sys.stdin.readline().split()))
    #print a[ch1-1],b[ch2-1]
    #print check(a[ch1-1],b[ch2-1])
    print "Case #"+str(i+1)+": "+str(check(a[ch1-1],b[ch2-1]))
    
myfile.close()
myin.close()

