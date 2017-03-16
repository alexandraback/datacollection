
    

def getpiece1(num:int,c:list)->int:    
    if num==1:
        return 0
    else:
        piece=0
        for i in range(num-1):
            if c[i]>c[i+1]:
                piece+=c[i]-c[i+1]
        return piece 
def getpiece2(num:int,c:list)->int:    
    if num==1:
        return 0
    else:
        max_rate=0
        for i in range(num-1):
            if c[i]>c[i+1]:
                max_rate=max(max_rate,c[i]-c[i+1])
        piece=0
        for i in range(num-1):
            if c[i]>max_rate:
                piece+=max_rate
            else:
                piece+=c[i]
                
        return piece    
    
       
new=open("A-small-attempt0.in")

new1=open("output.txt","w")
n1=new.readline()
for i in range(int(n1)): 
    a=new.readline()
    b=new.readline()
    c=[int(j) for j in b.split()]
    num=int(a)
    piece1=getpiece1(num,c)
    piece2=getpiece2(num,c)
    new1.write('Case #'+str(i+1)+': '+str(piece1)+' '+str(piece2)+'\n')     
                
                
    
 
    

        
     

