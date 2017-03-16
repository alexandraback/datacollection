input_file = "B-small-attempt1.in"
#input_file = "sample_input.txt"


def line(f,_type=str):
    s = [_type(i) for i in f.readline().strip().split()]
    return s


def f(b,n,L):
    if n <= b:
        return n
    q = int((n - 1 - b) / sum(1./i for i in L)) #starting time to search from
    c = sum(q / i + 1 for i in L) #customers served
    t = [-q % i for i in L] #time spent so far
    for i in xrange(b):
        if t[i] == 0:
            t[i] = L[i]
    while True:
        t = [i - 1 for i in t]
        for i in xrange(b):
            if t[i] == 0:
                c += 1
                if c == n:
                    return i + 1
                t[i] = L[i]
                
    


with open(input_file) as fin:
    with open('output.txt','w') as fout:
        T = line(fin,int)[0]
        for case in range(1,T+1):
            b,n = line(fin,int)
            L = line(fin,int)

            answer = f(b,n,L)
            
            s = "Case #%d: %d\n" % (case, answer)
            print s,
            fout.write(s)
