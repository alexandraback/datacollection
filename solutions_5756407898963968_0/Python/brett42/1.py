def go():
    f=open('in.txt')
    c=int(f.readline())
    for case in range(1,c+1):
        a1=int(f.readline())-1
        l1=[]
        for s in range(4):
            l1.append(set(f.readline().split()))
        a2=int(f.readline())-1
        l2=[]
        for s in range(4):
            l2.append(set(f.readline().split()))
        print 'Case #%d:'%case,
        i=l1[a1].intersection(l2[a2])
        if len(i)==0:
            print 'Volunteer cheated!'
        elif len(i)>1:
            print 'Bad magician!'
        else:
            print list(i)[0]
            
    f.close()


    
