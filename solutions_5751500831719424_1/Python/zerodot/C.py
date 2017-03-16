
def firsts(li):
    return [e[0] for e in li]

def seconds(li):
    return [e[1] for e in li]

def rezipper(li):
    r=len(li[0])
    return [[e[i] for e in li] for i in range(r)]

def dists(li):
    return min([sum([abs(e-i) for e in li]) for i in li])
    
def counts(li):
    ans=[(li[0],1)]
    for i in range(1,len(li)):
        if li[i]==li[i-1]:
            ans=ans[:-1]+[(ans[-1][0],ans[-1][1]+1)]
        else:
            ans=ans+[(li[i],1)]
    return ans

def solve(strings):
    comps=[counts(e) for e in strings]
    fs=[firsts(e) for e in comps]
    f=fs[0]
    for e in fs:
        if e!=f: return "Fegla Won"
    else:
        # "Omar Won"
        fs=rezipper([seconds(e) for e in comps])
        return str(sum([dists(e) for e in fs]))
    
if __name__=="__main__":
    cases=int(input())
    for i in range(1,cases+1):
        strs=int(input())
        ans=solve([input() for j in range(strs)])
        print("Case #"+str(i)+": "+str(ans))
