f=open('/Users/pruthvikarreddy/Downloads/A-small-attempt0.in').read()
o = open('/Users/pruthvikarreddy/Downloads/out.txt','w')


c=0
v=f.splitlines()
i=1
for ix,x in enumerate(f.splitlines()[1::10]):
    ra=v[i]
    r=[[int(j) for j in k.split(' ')] for k in v[i+1:i+5]]
    ca=v[i+5]
    c=[[int(j) for j in k.split(' ')] for k in v[i+6:i+10]]
    
    i+=10
    tc=c[int(ca)-1]

    tr=r[int(ra)-1]
    sols= set(tr).intersection(tc)
    if len(sols)==1:
        o.write('Case #'+str(ix+1)+': '+str(list(sols)[0])+'\n')
    elif len(sols)==0:
        o.write('Case #'+str(ix+1)+': '+'Volunteer cheated!'+'\n')
    else:
        o.write('Case #'+str(ix+1)+': '+'Bad magician!'+'\n')