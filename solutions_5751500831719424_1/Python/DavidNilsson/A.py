from collections import deque
f = open('./A-large.in')
#f = open('./test.in')
nbrs = deque([k for k in f.read().split()])
f.close()

def hasnext():
    return len(nbrs) > 0

def read():
    return nbrs.popleft()

def strip_words(w):
    r = w[0]
    count = [1]
    for k in range(1, len(w)):
        if w[k] != r[-1]:
            r += w[k]
            count.append(0)
        count[-1] += 1
    return [r, count]

def min_dist(nbrs):
    r = 100*100
    for k in range(1, 101):
        r = min(r, sum([abs(k-i) for i in nbrs]))
    return r

f = open('out.txt', 'w')
cases = int(read())
for cc in range(1, cases+1):
    N = int(read())
    words = []
    counter = []
    
    for k in range(N):
        words.append(read())
        counter.append(strip_words(words[k]))
    
    ok = True
    for k in range(1, N):
        if counter[0][0] != counter[k][0]:
            ok = False
    
    if ok:
        count = 0
        for k in range(len(counter[0][1])):
            count += min_dist([counter[i][1][k] for i in range(N)])
        
    f.write("Case #" + str(cc) + ": ")
    if ok:
        f.write(str(count) + "\n")
    else:
        f.write("Fegla Won\n")
f.close()