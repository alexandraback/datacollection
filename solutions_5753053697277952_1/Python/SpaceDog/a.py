import sys
import logging
# logging.basicConfig(format="    %(message)s", level=logging.DEBUG)

testCases = int(input()) 
    
for testCase in range(1, testCases + 1):

    n = int(input())
    p = list(map(int, sys.stdin.readline().strip().split()))  
    a = []; ai = 0;

    logging.debug("Case #" + str(testCase) + ": ")            
    
    logging.debug("   N: "+str(n))
    logging.debug("   P: "+str(p))
    
    s = sum(p)
    while (s > 0):
        m = max(p)
        i = p.index(m)
        s -= 1
        p[i] -= 1;
        nm = max(p)

        a.append(str(chr(ord('A')+i)))
        
        logging.debug("  Removing "+str(i)+" (sum = "+str(s)+", max = "+str(nm)+") AI: "+str(a[ai])+" P: "+str(p))
        if ((s > 2) or (s == 1)) and (nm == m):
            i = p.index(m)
            s -= 1
            p[i] -= 1
            nm = max(p)       
            a[ai] += str(chr(ord('A')+int(i)))
            logging.debug("  Also removing "+str(i)+" (sum = "+str(s)+", max = "+str(nm)+") AI: "+str(a[ai])+" P: "+str(p))
        
        ai += 1
        
    print("Case #" + str(testCase) + ": " + " ".join(a))
             
