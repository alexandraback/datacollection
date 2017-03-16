data_in = open("A-small-attempt0.in", "r")
data_out = open("MushroomMonster.out", "w")

T = int(data_in.readline())

for t in xrange(T):
    data_out.write("Case #%d: "%(t+1))
    N = int(data_in.readline())
    m_str = data_in.readline().split()
    m = []
    for i in m_str:
        m.append(int(i))
    
    max_diff = 0
    y = 0
    for i in xrange(1, N):
        if m[i] < m[i-1]:
            diff = m[i-1] - m[i]
            y += diff
            if diff > max_diff:
                max_diff = diff
    z = 0
    for i in xrange(1, N):
        diff = m[i-1] - m[i]
        if m[i-1] < max_diff:
            z += m[i-1]
        else:
            z += max_diff
            
    data_out.write("%d %d\n"%(y,z))
    
data_in.close()
data_out.close()
