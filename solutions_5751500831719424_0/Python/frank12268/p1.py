import sys

def main(ifn='ain.txt',ofn='aout.txt'):
    sys.setrecursionlimit(2000)
    with open(ifn) as inf:
        with open(ofn,'w') as ouf:
            noc = int(inf.readline())
            for tnoc in xrange(1,noc+1):
                ouf.write("Case #%d: " %(tnoc))
                print "Case #%d: " %(tnoc)
                n = int(inf.readline())
                ss = []
                for i in xrange(n):
                    ss.append(inf.readline().strip())
                aa = [[s[i] for i in xrange(len(s)) if (i==0) or (s[i]!=s[i-1])] for s in ss]
                m = len(aa[0])
                flag = True
                for i in xrange(n-1):
                    if aa[i]!=aa[i+1]:
                        flag = False
                        break
                if not flag:
                    ouf.write("Fegla Won\n")
                    print "Fegla Won"
                    continue
                bb = [[i for i in xrange(len(s)) if (i==0) or (s[i]!=s[i-1])] for s in ss]
                cc = [[s[i+1]-s[i] if i<len(s)-1 else len(ss[j])-s[i] for i in xrange(len(s))] for j,s in enumerate(bb)]
                dd = [[x[i] for x in cc] for i in xrange(m)]
                bestAnswer = 0
                for i in xrange(m):
                    dd[i].sort()
                    l = len(dd[i])
                    for j in xrange(l/2):
                        bestAnswer += dd[i][l-1-j]-dd[i][j]
                ouf.write("%d\n" %(bestAnswer))
                print "%d" %(bestAnswer)

