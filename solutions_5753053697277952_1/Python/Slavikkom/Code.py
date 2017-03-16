file = open('C:\\Users\\V\\Downloads\\a.txt','r')
f = file.read()
result=f.split("\n")
file.close()
file = open('C:\\Users\\V\\Downloads\\Submit.txt','w')
n = int(result[0])
for i in range(n):
    file.write("Case #" + str(i) + ": ")
    m = int(result[2 * i + 1])
    res = []
    re = result[2 * i + 2].split(" ")
    for j in re:
        res.append(int(j))
    d = dict()
    j = 0
    for k in res:
        d[chr(65 + j)] = k
        j = j + 1
    counter = 0
    while counter < 10000:
        if len(d.values()) == 0:
            break
        a = max(d.values())
        c = 0
        keys = []
        for k in d.keys():
            if d[k] == a:
                keys.append(k)
                c = c + 1
        if len(keys) == 1:
            file.write(str(keys[0] + " "))
            if d[keys[0]] > 1:
                d[keys[0]] =  d[keys[0]]  - 1
            else:
                del d[keys[0]]
        if len(keys) == 2:
            file.write(str(keys[0] + str(keys[1]) + " "))  
            if d[keys[0]] > 1:
                d[keys[0]] =  d[keys[0]]  - 1
            else:
                del d[keys[0]]
            if d[keys[1]] > 1:
                d[keys[1]] =  d[keys[1]]  - 1
            else:
                del d[keys[1]]    
        if len(keys) > 2:
            file.write(str(keys[0] + " "))  
            if d[keys[0]] > 1:
                d[keys[0]] =  d[keys[0]]  - 1
            else:
                del d[keys[0]]
        if len(keys) == 0:
            break
        counter = counter + 1    
    file.write("\n")        
file.close()