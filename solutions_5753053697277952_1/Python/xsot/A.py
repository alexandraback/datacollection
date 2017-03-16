for t in range(1, int(input())+1):
    n = int(raw_input())
    p = map(int, raw_input().split())
    rem = sum(p)
    a = [[v, chr(65+i)] for i,v in enumerate(p)]
    
    print "Case #%d:" % t, 
    
    while rem:
        a.sort(reverse=True)
        if rem % 2 == 1 and a[0][0]*2 <= rem:
            a[0][0] -= 1
            rem -= 1
            print a[0][1],
        else:
            a[0][0] -= 1
            a[1][0] -= 1
            rem -= 2
            print a[0][1]+a[1][1],
    print
            
        
    
