def methd1(case_stat):
    min1 = 0
    prev = case_stat[0]
    for curn in case_stat:
        if(prev >= curn):
            min1 += prev -curn
        prev = curn
    return min1

def methd2(case_stat):
    min2 = 0
    prev = case_stat[0]
    sped = 0
    for curn in case_stat:

        diff = prev - curn
            
        if(sped < diff):
            sped = diff
        prev = curn
    print(sped)
    prev = case_stat[0]
    for i in range(0,len(case_stat)-1):
        
        min2 += min(case_stat[i],sped)
    
    return min2


def procEachCase(case_stat):
    rsut1 = methd1(case_stat)
    rsut2 = methd2(case_stat)
    return [rsut1,rsut2]
    return "possible"


#---- main code here
filepath = "A-large.in"
tt = "A-small-attempt1.in"
anspath = "answer"

file = open(filepath,'r')
ans_file = open(anspath,'w')

str_T = file.readline()
T = int(str_T)
print(T)
for i in range(1,T+1):
    print("case",i)
    str_N = file.readline()
    N = int(str_N)

    str_case = file.readline()
    case_group = str_case.split(" ")
    case_stat = []
    for j in range(0,N):
        case_stat.append( int(case_group[j]))
    
    print(case_stat)
    answer = procEachCase(case_stat)
    print(answer)
    #print(answer)
    ans_file.write("Case #%d: %d %d\n" %(i,answer[0],answer[1]))
    #ans_file.write("%d,%d,%d, Case #%d: %s\n" %(X,R,C,i,answer))

ans_file.close()
file.close()

