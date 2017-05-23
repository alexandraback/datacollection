fi=open('inp.in','r')
fo=open('outp.in','w')

t=int(fi.readline().rstrip('\n'))
outs=''
for case in range(1,t+1):
    n=int(fi.readline().rstrip('\n'))
    a=[int(i)for i in fi.readline().rstrip('\n').split(' ')]
    tot=0
    for i in range(n):
        tot+=a[i]
    ans=''
    while tot:
        mx=-1
        mxid=-1
        for i in range(n):
            if a[i]>mx:
                mx=a[i]
                mxid=i
        ans+=(chr(ord('A')+mxid))
        a[mxid]-=1
        tot-=1
        if tot:
            mx = -1
            mxid = -1
            for i in range(n):
                if a[i] > mx:
                    mx = a[i]
                    mxid = i
            for i in range(n):
                if i==mxid:
                    continue
                if a[i]>(tot-1)//2:
                    break
            else:
                ans+=(chr(ord('A')+mxid))
                a[mxid]-=1
                tot-=1
        ans+=' '
    ans=ans.rstrip(' ')
    outs+=('Case #'+str(case)+': '+ans+'\n')

fo.write(outs)
fo.close()
fi.close()
