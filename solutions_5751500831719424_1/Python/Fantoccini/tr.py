'''
Created on 04/05/2014

@author: tianyizhu
'''
from multiprocessing import Process, Manager

def func(ci, res, n, l):
    res[ci] = "Fegla Won"
    r = 0
    while len(l[0]) > 0:
        #print l
        ch = l[0][0]
        #print ch
        cnt = []
        mxc = 0
        for i in xrange(n):
            tc = 0
            for j in xrange(len(l[i])):
                if l[i][j] == ch:
                    tc += 1
                else:
                    break
            if tc == 0:
                return
            if tc > mxc:
                mxc = tc
            cnt.append(tc)
            l[i] = l[i][tc:]
        mir = mxc * n
        #print cnt, mxc, mir
        
        for i in xrange(mxc):
            tc = 0
            for j in xrange(n):
                tc += abs(i + 1 - cnt[j])
            if tc < mir:
                mir = tc
        #print cnt, mir
        
        r += mir
    for i in xrange(n):
        if len(l[i]) > 0:
            return
    res[ci] = r
    
if __name__ == "__main__":
    ps = []
    manager = Manager()
    fin = open("tr.in", "r")
    fout = open("tr.out", "w")
    t = int (fin.readline())
    res = manager.list(range(t))
    for ci in xrange(t):
        n = int(fin.readline())
        l = []
        for dummy in xrange(n):
            l.append(fin.readline().strip())
        p = Process(target=func, args=(ci, res, n, l))
        ps.append(p)
        p.start()
    for ci in xrange(t):
        ps[ci].join()
        fout.write("Case #%d: %s\n" % (ci + 1, str(res[ci])))
    fout.close()
    fin.close()
