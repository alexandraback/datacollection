def gcd(m, n):
    return m if n == 0 else gcd(n, m % n)

def lcm(m, n):
    return m * n // gcd(m, n)



def procEachCase(B,N,case_stat):
    
    chunktime = case_stat[0]
    for M in case_stat:
        chunktime = lcm(M,chunktime)
    #print(chunktime)

    chunk_users = 0
    for M in case_stat:
        chunk_users += chunktime//M
    #print(chunk_users)

    chunk_seq = []
    for i in range(0,chunktime):
        avail_B = []
        for j in range(0,B):
            if(i%case_stat[j] == 0):
                avail_B.append(j+1)
        if avail_B:
            for k in avail_B:
                chunk_seq.append(k)
    #print(chunk_seq)

    n = N%chunk_users
    #print(n)
    #print(chunk_seq[n])
    return chunk_seq[n-1]


#---- main code here
filepath = "B-small-attempt1.in"
anspath = "answer"

file = open(filepath,'r')
ans_file = open(anspath,'w')

str_T = file.readline()
T = int(str_T)
print(T)
for i in range(1,T+1):
    print("case",i)
    str_BN = file.readline()
    B_N = str_BN.split(" ")
    B = int(B_N[0])
    N = int(B_N[1])
    print(B,N)

    str_case = file.readline()
    case_group = str_case.split(" ")
    case_stat = []
    for j in range(0,B):
        case_stat.append( int(case_group[j]))
    
    #print(case_stat)
    answer = procEachCase(B,N,case_stat)
    #print(answer)
    #print(answer)
    ans_file.write("Case #%d: %d\n" %(i,answer))
    #ans_file.write("%d,%d,%d, Case #%d: %s\n" %(X,R,C,i,answer))

ans_file.close()
file.close()

