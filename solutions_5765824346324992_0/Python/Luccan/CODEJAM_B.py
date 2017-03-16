def sol():
    def simulate(N,M):
        l = []
        for item in M:
            l.append(0)
        queue_head = 1
        lcm_timer = 0
        while (True):
            _min = min(l)
            while (_min==0): #while there is a free barber
                _min = min(l)
                #Find least index free Barber
                for i in range(len(l)):
                    if (l[i]==0):
                        l[i] = M[i]
                        if (queue_head==N):
                            return i+1
                        queue_head+=1
                        break
            lcm_timer+=_min
            lcm = True
            for i in range(len(l)):
                l[i]-=_min
                if (l[i]!=0):
                    lcm = False
            if (lcm):
                print lcm_timer, queue_head, N, M
                return simulate((N-1)%(queue_head-1)+1, M)
    
    global line_counter
    _BN = inp[line_counter].split()
    B = int(_BN[0])
    N = int(_BN[1])
    line_counter+=1
    _l = inp[line_counter].split()
    line_counter+=1
    l = []
    for data in _l:
        l.append(int(data))
    return str(simulate(N,l))
    
##with open('lol.txt', 'r') as f:
with open('B-small-attempt0 (1).in', 'r') as f:
##with open('B-large (1).in', 'r') as f:
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
