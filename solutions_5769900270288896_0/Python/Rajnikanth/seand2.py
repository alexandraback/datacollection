def inside(i,j,k):
    a = (j<=i)
    b = (i<=k)
    return (a and b)
def calc(build,unhapp,r,c):
    for i in xrange(r):
        for j in xrange(c):
            x = i+1
            y = j
            if(inside(x,0,r-1) and inside(y,0,c-1)):
                if(build[x][y]==1):
                    unhapp[i][j]+=1
            x = i-1
            y = j
            if(inside(x,0,r-1) and inside(y,0,c-1)):
                if(build[x][y]==1):
                    unhapp[i][j]+=1
            x = i
            y = j+1
            if(inside(x,0,r-1) and inside(y,0,c-1)):
                if(build[x][y]==1):
                    unhapp[i][j]+=1
            x = i
            y = j-1
            if(inside(x,0,r-1) and inside(y,0,c-1)):
                if(build[x][y]==1):
                    unhapp[i][j]+=1
t = input()
for ij in xrange(1,t+1):
    inp = raw_input().split()
    r = int(inp[0])
    c = int(inp[1])
    n = int(inp[2])
    build = []
    unhapp = []
    check = []
    for i in xrange(r):
        build += [[1]*c]
        unhapp += [[1]*c]
    calc(build,unhapp,r,c)
    tot = 0
    ni=(r*c)-n
    while(ni!=0):
        ni-=1
        flag=0
        for x in xrange(0,r):
            for y in xrange(0,c):
                if(build[x][y]==1 and flag==0):
                    flag = 1
                    I = x
                    J = y
                elif(build[x][y]==1):
                    if(unhapp[x][y]>unhapp[I][J]):
                        I = x
                        J = y
        build[I][J]=0
        calc(build,unhapp,r,c)
    
    for i in xrange(r):
        for j in xrange(c):
            if(build[i][j]==0):
                continue
            X = i*c + j
            x = i+1
            y = j
            Y = x*c + y
            if(inside(x,0,r-1) and inside(y,0,c-1)):
                if(build[x][y]==1):
                    if((X,Y) not in check):
                        tot+=1
                        check += [(X,Y),(Y,X)]
            x = i-1
            y = j
            Y = x*c + y
            if(inside(x,0,r-1) and inside(y,0,c-1)):
                if(build[x][y]==1):
                    if((X,Y) not in check):
                        tot+=1
                        check += [(X,Y),(Y,X)]
            x = i
            y = j+1
            Y = x*c + y
            if(inside(x,0,r-1) and inside(y,0,c-1)):
                if(build[x][y]==1):
                    if((X,Y) not in check):
                        tot+=1
                        check += [(X,Y),(Y,X)]
            x = i
            y = j-1
            Y = x*c + y
            if(inside(x,0,r-1) and inside(y,0,c-1)):
                if(build[x][y]==1):
                    if((X,Y) not in check):
                        tot+=1
                        check += [(X,Y),(Y,X)]
    print "Case #"+str(ij)+":",tot
