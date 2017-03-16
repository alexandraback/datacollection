t=input()
for case in range(0,t):
    u_row1=input()
    grid1=[]
    for i in range(0,4):
        row=[]
        for item in raw_input().split():
            row.append(item)
        grid1.append(row)
    r1=set(grid1[u_row1-1])
    u_row2=input()
    grid2=[]
    for i in range(0,4):
        row=[]
        for item in raw_input().split():
            row.append(item)
        grid2.append(row)
    r2=set(grid2[u_row2-1])
    r3=r1.intersection(r2)
    #print r3
    if len(r3)==1:
        print "Case #%d: %d"%(case+1,int(list(r3)[0]))
    if len(r3)>1:
        print "Case #%d: Bad magician!"%(case+1)
    if len(r3)==0:
        print "Case #%d: Volunteer cheated!"%(case+1)