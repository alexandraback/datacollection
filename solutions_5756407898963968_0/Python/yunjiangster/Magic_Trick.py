import sys
tmp=[]
for i,line in enumerate(sys.stdin):
    if i == 0:
        n = int(line.strip('\r\t\n '))
    else:
        tmp.append(line.strip('\r\t\n '))
assert len(tmp) % 10 == 0
template='Case #%s: %s'
for i in xrange(n):
    row1=int(tmp[10*i])
    row2=int(tmp[10*i + 5])
    set1=set(tmp[10*i + row1].split(' '))
    set2=set(tmp[10*i + 5 + row2].split(' '))
    inter = set1.intersection(set2)
    if len(inter) == 1:
        print template%(i+1,inter.pop())
    elif len(inter) > 1:
        print template%(i+1,'Bad magician!')
    else:
        print template%(i+1,'Volunteer cheated!')

