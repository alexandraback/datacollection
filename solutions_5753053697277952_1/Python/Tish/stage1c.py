import sys



f = open('C:\\Users\\Tish\\Desktop\\input3.in', 'r')
g = open('C:\\Users\\Tish\\Desktop\\output.txt', 'w')
def read():
        return f.readline()
    
def finish(a):
    for i in range(10):
        if (a[i]==0):
            return 0
    return 1


def output(i,out):
    g.write('Case #'+str(i+1)+': '+str(out)+'\n')

def my_print(x):
    g.write(x)



def q1():
    n=int(read())
    a=read().strip().split(' ')
    for i in range(n):
        a[i]=int(a[i])

    m=0
    m2=0
    ind=-1
    ind2=-1
    for i in range(n):
        if (m<a[i]):
            m=a[i]
            ind=i
    for i in range(n):
        if i != ind:
            if (m2<a[i]):
                m2=a[i]
                ind2=i
    res=""
    for i in range(m-m2):
        res=res+ chr(ord('A')+ind)+" "
    for i in range(n):
        if i != ind and i != ind2:
            for j in range(a[i]):
                res=res+chr(ord('A')+i)+" "
    for i in range(m2-1):
        res=res+chr(ord('A')+ind)+chr(ord('A')+ind2)+" "
    res=res+chr(ord('A')+ind)+chr(ord('A')+ind2)
    return res
def main():
    t = int(read())
    for i in range(t):
        output(i,q1())
    g.close()

            
                
main()
