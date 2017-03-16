
def getnum(num1:int,num2:int,c:list)->int:    
    if num2<num1:
        return num2
    else:
        min_val=min(c)
        max_val=0
        
        while max_val-min_val>=2 or max_val==0:
            count=0
            check=0
            if max_val==0:
                for i in range(num1):
                    
                    count+=int((2*min_val)/c[i])

                    if (2*min_val)%c[i]!=0:
                    
                        count+=1
                    else:
                        check+=1
                if count<num2-1 or (check==0 and count==num2-1):
                    min_val=2*min_val
                elif count>=num2-1:
                    max_val=2*min_val
              
                    
                
            else:
                count=0
                mid=int((max_val+min_val)/2)
                for i in range(num1):
                    count+=int(mid/c[i])
                    if mid%c[i]!=0:
                        
                        count+=1
                    else:
                        check+=1
                if count<num2-1 or (check==0 and count==num2-1):
                    min_val=mid
                elif count>=num2-1:
                    max_val=mid
                
                    
        
        
        count=0
        for i in range(num1):
            count+=int(min_val/c[i])
            if min_val%c[i]!=0:
                count+=1
    #    print(count,min_val,max_val,num2,c)
        if count<num2:
            diff=num2-count            
            num0=min_val
            for i in range(num1):
                if num0%c[i]==0:
                    diff-=1
                if diff==0:
                    return i
        
            if diff>0:
                num0+=1
                for i in range(num1):
                    if num0%c[i]==0:
                        diff-=1
                    if diff==0:
                        return i
                           
                
        else:
            for i in range(num1):
                if (min_val-1)%c[num1-i-1]==0:
                    return num1-i-1
      #  print(0)
                
        return 0
       
 
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
    
       
new=open("B-large.in")

new1=open("output.txt","w")
n1=new.readline()
for i in range(int(n1)): 
    a=new.readline()
    b=new.readline()
    c=[int(j) for j in b.split()]
    [num1,num2]=[int(j) for j in a.split()]
    num=getnum(num1,num2,c)
    new1.write('Case #'+str(i+1)+': '+str(num+1)+'\n')     
                
                
    
 
    

        
     

