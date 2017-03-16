def solve(l):
    result = []
    while len(l)>1:
        i = iter(l)
        a,b = next(i), next(i)
        n = min(l[a], l[b])
        if l[a]==n:
            l.pop(a)
        else:
            l[a] -= n
        if l[b]==n:
            l.pop(b)
        else:
            l[b] -= n
        result.append((n, chr(ord('A')+a)+chr(ord('A')+b)))
    if len(l):
        if l[next(iter(l))]%2==0:
            result.append((l[next(iter(l))]//2, chr(ord('A')+next(iter(l)))+chr(ord('A')+next(iter(l)))))
        else:
            if l[next(iter(l))]>2:
                result.append((l[next(iter(l))]//2, chr(ord('A')+next(iter(l)))+chr(ord('A')+next(iter(l)))))
            result.append((1, chr(ord('A')+next(iter(l)))))
    return " ".join([" ".join([j for k in range(i)]) for i,j in result[::-1]])
    
        
        

filename = "A-small-attempt0.in"
f = open(filename,"r")
fout = open(filename.replace(".in", ".out"), "w")
N = int(f.readline())
for i in range(N):
    f.readline()
    l = [int(i) for i in f.readline().strip().split()]
    res = solve(dict(zip(range(len(l)), l)))
    print("Case #{}:".format(i+1), res)
    print("Case #{}:".format(i+1), res,file=fout)
f.close()
fout.close()