import sys
T=int(input())
for case_id in range(1,T+1):
    N=int(input())
    arr=list(map(int,input().split()))
    def solve():
        def get_max():
            res = max((x,i,chr(ord('A')+i)) for i,x in enumerate(arr))
            arr[res[1]]-=1
            return res[2]
                    
        res = []
        s = sum(x for x in arr)
        while s>0:
            if s>3 or s==2:
                res.append(get_max()+get_max())
            elif s==3:
                res.append(get_max())
            s = sum(x for x in arr)
        return ' '.join(res)

    ans = solve()
    print('Case #%d: %s' % (case_id, ans))
    print('Case #%d: %s' % (case_id, ans), file=sys.stderr)
