inp = open(r"F:\Nir\Downloads\A-large.in",'r')
out = open(r"F:\Nir\Downloads\njy\q1.out", 'w')
l = inp.readlines()

a = []
t = int(l[0])
idx = 1
for i in range(t):
    n = int(l[idx])
    idx += 1
    arr = [int(num) for num in l[idx].split(" ")]
    idx += 1
    r = []

    while max(arr) != 0:
        v, i = max([ (v,i) for i,v in enumerate(arr)])
        arr[i] -= 1
        s = chr(ord('A')+i)
        if 2*max(arr) > sum(arr):
            v, i = max([ (v,i) for i,v in enumerate(arr)])
            arr[i] -= 1
            s += chr(ord('A')+i)
        r.append(s)

    a.append(" ".join(r))

for i in range(t):
    out.write("Case #{0}: {1}\n".format(i+1,a[i]))
out.close()