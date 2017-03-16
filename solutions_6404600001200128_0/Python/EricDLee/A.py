# python A.py < A-small-attempt0.in > A-small-attempt0.out
# 
# list(raw_input()) # List of chars
# [int(n) for n in raw_input().split()] # List of ints

if __name__ == "__main__":
    testcases = input()
    
    for case in xrange(1, testcases+1):
        
        num = int(raw_input())
        m = [int(n) for n in raw_input().split()]
        negative_diff = [int(m[i]) - int(m[i+1]) for i in range(int(num)-1)]
        
        method_1 = sum([max(0, x) for x in negative_diff])
        rate = max(0, max(negative_diff))
        method_2 = sum([min(rate, m[i]) for i in range(int(num)-1)])
        
        
        print("Case #%i: %s" % (case, str(method_1) + " " + str(method_2)))
