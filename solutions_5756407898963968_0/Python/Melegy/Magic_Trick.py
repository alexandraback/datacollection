def solve (r1,grid1,r2,grid2):
    set1=set(grid1[r1-1])
    set2=set(grid2[r2-1])
    inter=set1.intersection(set2 )
    if len(inter)==1:
        return list(inter)[0]
    elif len(inter)==0:
        return "Volunteer cheated!"
    elif len(inter)>1:
        return "Bad magician!"
      
fin=open('../in','r') ; fout=open('../out','w')
cases=int(fin.readline().strip())
for case in range(1,cases+1):
    r1=int(fin.readline())
    grid1=[]
    for i in range(4):
        row=[int(x) for x in fin.readline().strip().split(' ')]
        grid1.append(row)
    r2=int(fin.readline())
    grid2=[]
    for i in range(4):
        row=[int(x) for x in fin.readline().strip().split(' ')]
        grid2.append(row)
    fout.write("Case #"+str(case)+": "+str(solve(r1,grid1,r2,grid2))+"\n")