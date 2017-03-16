import sys

def ifSmall(e1, e2):
    if e1[0]<e2[0]:
        return True
    if e1[0]==e2[0] and e1[1]<e2[1]:
        return True
    return False

def push(h, e):
        h.append(e)
        pos = len(h)-1
        while pos>0 and ifSmall(e,h[(pos-1)/2]):
            h[pos] = h[(pos-1)/2]
            pos = (pos-1)/2
        h[pos] = e
        return h
    
def pop(h):
        temp = h[0]
        h[0] = h[-1]
        h.pop()
        h = [(x[0]-temp[0], x[1]) for x in h]
        pos = 0
        while pos<=(len(h)-2)/2:
            child = pos*2+1
            if child+1<len(h) and ifSmall(h[child+1],h[child]):
                child += 1
            if ifSmall(h[pos],h[child]):
                break
            t = h[pos]
            h[pos] = h[child]
            h[child] = t
            pos = child
        return temp, h

f = open('B-small.in')
f_out = open('B-small.out', 'w')

T = int(f.readline())
for k in range(T):
    line = f.readline().split()
    B = int(line[0])
    N = int(line[1])
    line = f.readline().split()
    M = [int(_) for _ in line]
    product = 1
    for i in range(B):
        product *= M[i]
    div = sum([product/x for x in M])
    N %= div
    if N==0:
        N = div
    heap = [(0, x) for x in range(B)]
    while (N>0):
        pair, heap = pop(heap)
        heap = push(heap, (M[pair[1]], pair[1]))
        #print heap
        N -= 1
    ans = pair[1]+1
    f_out.write('Case #{0}: {1}\n'.format(k+1, ans))

f.close()
f_out.close()
