input_file = "A-large.in"


def line(f,_type=str):
    s = [_type(i) for i in f.readline().strip().split()]
    return s


with open(input_file) as fin:
    with open('output.txt','w') as fout:
        T = line(fin,int)[0]
        for case in range(1,T+1):
            n = line(fin,int)[0]
            L = line(fin,int)

            a = 0
            for i in range(len(L)-1):
                if L[i+1] < L[i]:
                    a -= L[i+1] - L[i]

            b = 0
            L2 = [L[i] - L[i+1] for i in range(len(L)-1)]
            e = max(L2)
            for i in L[:-1]:
                b += min(e,i)
            
            s = "Case #%d: %d %d\n" % (case, a, b)
            print s
            fout.write(s)
