def sol():
    def firstqn(l):
        min_eaten = 0
        lastdata = 0
        for data in l:
            if (lastdata-data>0):
                min_eaten+=lastdata-data
            lastdata = data
        return min_eaten
    def secondqn(l):
        eat_rate = 0
        lastdata = -1
        for data in l:
            if (lastdata!=-1):
                if (lastdata-data>eat_rate):
                    eat_rate = lastdata-data
            lastdata = data
        min_eaten = 0
        for i in range(len(l)-1):
            data = l[i]
            if (data>=eat_rate):
                min_eaten+=eat_rate
            else:
                min_eaten+=data
        return min_eaten
    global line_counter
    no_data = int(inp[line_counter])
    line_counter+=1
    _l = inp[line_counter].split()
    line_counter+=1
    l = []
    for data in _l:
        l.append(int(data))
    return str(firstqn(l)) + " " + str(secondqn(l))
    
##with open('lol.txt', 'r') as f:
with open('A-small-attempt0 (1).in', 'r') as f:
##with open('A-large.in', 'r') as f:
    inp = f.readlines()
    f.close()
line_counter = 0
T = int(inp[line_counter])
line_counter+=1
data = ''
for i in range(T):
    print i
    data += 'Case #%d:' %(i+1) + ' ' + sol()+'\n'
with open('output.txt', 'w') as f:
    f.write(data)
    f.close()
print data
print 'done!'
