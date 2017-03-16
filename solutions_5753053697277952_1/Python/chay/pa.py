T=int(input())
for t in range(T):
    n=int(input())
    a=input().split(' ')
    num=[[int(a[i]),chr(ord('A')+i)] for i in range(len(a))]
    str_=[]
    while len(num)>2:
        num=sorted(num,key=lambda x: (-x[0],x[1]))
        num[0][0]-=1;
        str_.append(num[0][1])
        if num[0][0]==0:
            num.remove(num[0])
        #print(num)
    while num[0][0]>0:
        str_.append(num[0][1]+num[1][1])
        num[0][0]-=1
    #print(str_)
    print("Case #{0}: {1}".format(t+1,' '.join(str_)))
