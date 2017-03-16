#!/usr/bin/env python

from sys import stdin
from numpy import array

T = int(stdin.readline())

for t in range(T):
    N = int(stdin.readline())
    st = []
    for n in range(N):
        buf = stdin.readline().strip()
        i = 0
        cnt = 0
        s = []
        while i < len(buf):
            c = buf[i]
            cnt += 1
            i += 1
            if i < len(buf) and buf[i] == c: continue
            s.append((c, cnt))
            cnt = 0
            pass
        st.append(s)
        pass

    print "Case #%d:" % (t+1),

    ret = 0
    wcnt = len(st[0])
    for s in st[1:]:
        if len(s) != wcnt:
            ret = None
            break
        pass

    if ret != None:
        st2 = zip(*st)
        for s in st2:
            char, num = zip(*s)
            for cc in char[1:]:
                if cc != char[0]:
                    ret = None
                    break
                pass
            if ret == None: break
            #print char, num
            nnum = array(num)
            nnum.sort()
            ret += sum(abs(nnum - nnum[len(nnum)/2]))
            pass
        pass

    if ret == None:
        print "Fegla Won"
    else:
        print ret
