file1 = open(r"C:\Users\Wu Jui Hsuan\Desktop\GCJ\proAAA.txt","r")
file = open(r"C:\Users\Wu Jui Hsuan\Desktop\GCJ\resultA.txt","w")

def mp():
    global file1  
    return map(int,file1.readline().split())
def ip():
    global file1  
    return file1.readline()
def it():
    global file1  
    return int(file1.readline())
def lt():  
    global file1
    return list(map(int,file1.readline().split()))
def pt(i,x):
    global file
    file.write("Case #%d: %s\n" % (i+1,x))
def ptlist(i,l): 
    global file
    file.write("Case #%d: %s" % (i+1,x) + ' '.join(map(str,l)))

#"Case #d:
from bisect import bisect_left
t = it()
for i in range(t):
    res = []
    n = it()
    b = lt()
    a = [(j,b[j]) for j in range(n)]
    a.sort(key = lambda x:x[1])
    b.sort()
    while b != []:
        if len(b) == 2:
            m = b.pop()
            b.pop()
            u = a.pop()[0]
            v = a.pop()[0]
            for _ in range(m):
                res.append(chr(u+65)+chr(v+65))
        else:
            r = b.pop()
            w = a.pop()[0]
            res.append(chr(w+65))
            r -= 1
            if r != 0:
                index = bisect_left(b,r)
                if index == len(b):
                    b.append(r)
                    a.append((w,r))
                else:
                    b.insert(index,r)
                    a.insert(index,(w,r))
    s = ' '.join(res)
    pt(i,s)
    
    


