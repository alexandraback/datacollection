
def solve(t):
    print "Case #%d:"%(t+1),
    
    n= int(raw_input())
    pn = map(int, raw_input().split())
    sn = map(list, zip(pn, range(n)))
    while(len(sn)>0):
        sn = sorted(sn, reverse=True)
        
        if len(sn)==2:
            ans = chr(ord('A')+sn[0][1]) + chr(ord('A')+sn[1][1])
            sn[0][0]-=1
            sn[1][0]-=1
            
            if sn[0][0]==0:
                sn = sn[2:]
            
        else:
            ans = chr(ord('A')+sn[0][1])
            sn[0][0]-=1
            if sn[0][0]==0:
                sn = sn[1:]
        
        print ans,
        
    print

    
    

def main():
    T = input()
    for i in xrange(T):
        solve(i)
    
if __name__=="__main__":
    main()