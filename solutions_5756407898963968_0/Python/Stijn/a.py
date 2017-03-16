f = open('D:/Projects/Python Environment/Projecten/Code Jam/2014/a/in.in')
T = int(f.readline().strip())
lines = []
for i in range(T*10): lines.append(f.readline().strip().split(' '))


fo = open('D:/Projects/Python Environment/Projecten/Code Jam/2014/a/out.out','wb'); 
for i in range(T):
    value = int(lines[i*10][0]);
    first = list(lines[i*10+value]);
    
    value = int(lines[i*10+5][0]);
    second = list(lines[i*10+5+value]);
    length = len(set(first).intersection( set(second) ))
    if(length>1): fo.write("Case #%d: Bad magician!\n" % (i+1))    
    elif(length>0): fo.write("Case #%d: %s\n" % (i+1,list(set(first).intersection( set(second) ))[0])); 
    elif(length==0): fo.write("Case #%d: Volunteer cheated!\n" % (i+1))
    
fo.close()