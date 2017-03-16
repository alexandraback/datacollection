
T = input() 

def func_a(A):
    n = len(A) 
    cnt = 0
    for i in range(n-1): 
        if A[i] > A[i+1]: 
            cnt += A[i] - A[i+1] 
    return cnt 

def func_b(A): 
    n = len(A) 
    rate = 0
    for i in range(n-1): 
        if A[i] > A[i+1] and A[i] - A[i+1] > rate: 
            rate = A[i] - A[i+1]

    cnt = 0
    for i in range(n-1): 
        cnt += min(A[i], rate) 
        
    return cnt 

for t in range(T): 
    n = input() 
    A = map(int, raw_input().split()) 
    print 'Case #%d:' %(t+1), func_a(A), func_b(A) 
