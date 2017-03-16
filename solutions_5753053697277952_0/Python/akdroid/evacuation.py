t=int(raw_input(''))

for case in range(1,t+1):
    
    n = int(raw_input(''))
    d = {}
    alph = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    total = 0
    inp = raw_input('').split()
    for i in range(n):
        d[ alph[i] ] = int(inp[i])
        total += d [alph[i]]

    print "Case #%d:"%case,
    while total > 0:
        parties = sorted(d.items(),key = lambda t: -t[1])
        #print parties
        #print total
        # Remove two
        maxval = parties[0][1]
        maxval2 = parties[1][1]
        if maxval - maxval2 >= 2:
            print parties[0][0]+parties[0][0],
            d[parties[0][0]]-=2
            total -=2
        elif maxval - maxval2 == 1:
            print parties[0][0],
            d[parties[0][0]]-=1
            total -= 1
        elif maxval == maxval2:
            if maxval2 > (total-1)/2:
                total -=2
                d[parties[0][0]]-=1
                d[parties[1][0]]-=1
                print parties[0][0]+parties[1][0],
            else:
                print parties[0][0],
                d[parties[0][0]]-=1
                total-=1
    print
            

