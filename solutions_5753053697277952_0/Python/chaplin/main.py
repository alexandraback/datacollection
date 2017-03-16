def problem_2016_1C_A():
    t=int(raw_input())
    for case in range(1,t+1):
        n=int(raw_input())
        senate=[int(item) for item in (raw_input().split())]
        senate = sorted([(senate[i], chr(65+i)) for i in range(len(senate))], reverse=True)
        ans=''
        while not senate[0][0]==0:
            ans=ans+senate[0][1]
            senate[0]=(senate[0][0]-1, senate[0][1])
            senate=sorted(senate, reverse=True)
        L = len(ans)
        ans=[ans[2*i:2*i+2] for i in range(0, L/2-1)] + ([ans[L-3], ans[L-2:L]] if L%2==1 else [ans[L-2:L]])
        print 'Case #'+str(case)+':',
        for item in ans:
            print item,
        print ''

def problem_2016_1C_B():
    pass

def problem_2016_1C_C():
    pass

def main():
    problem_2016_1C_A()
    
if __name__ == '__main__':
    main()
