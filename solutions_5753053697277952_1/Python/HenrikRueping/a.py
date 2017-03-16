filename  = "A-large.in"
f = open(filename,'r')
out = open("output.out",'w')
T =int(f.readline())
for Ca in range(T):
    N= int(f.readline())
    P=[int(j) for j in f.readline().split()]
    P=[[P[i],chr(ord('A') + i)] for i in range(len(P))]
    P=sorted(P,reverse=True)+[[0,'x']]
    #print(P)
    ret = ""
    for i in range(1,len(P)):
        
        cur = ' '.join([P[j][1] for j in range(i)])
        if len(cur)> 1:
            cur = cur[:len(cur)-2]+cur[len(cur)-1:]
        #print(str(i)+ ": "+str(P[i-1][0]-P[i][0]))
        #print("cur "+cur )
        ret+= (' '+cur)*(P[i-1][0]-P[i][0])    
    #print(ret)
    print("Case #"+str(Ca+1)+": "+ret+"\n")
    out.write("Case #"+str(Ca+1)+": "+ret+"\n")
f.close()
out.close()
