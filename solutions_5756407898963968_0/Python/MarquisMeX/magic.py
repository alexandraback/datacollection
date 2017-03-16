

if __name__ == '__main__':
    file_in=open('A-small-attempt4.in','r')
    file_out=open('output.out','w')
    loop = file_in.readline()
    
    for a in range(int(loop)):
        #first row number
        n=int(file_in.readline())
        
        remember=[]
        compare=[]
        #read the first n-1 lines
        for temp in range(n-1):
            file_in.readline()
            
        remember=map(int,file_in.readline().split(' '))

    
        for temp in range(4-n):
            file_in.readline()


        n=int(file_in.readline())
        
        for temp in range(n-1):
            file_in.readline()
            
        compare=map(int,file_in.readline().split(' '))

        
        ans=set(remember)&set(compare)

        for temp in range(4-n):
            file_in.readline()

            
        if len(ans)==0:
            file_out.write("Case #%d: Volunteer cheated!"%(a+1))
        elif len(ans)>1:
            file_out.write("Case #%d: Bad magician!"%(a+1))
        else:
            file_out.write("Case #%d: %d"%(a+1,ans.pop()))

        if a!=int(loop)-1:
            file_out.write("\n")
        
    file_in.close()
    file_out.close()
    
