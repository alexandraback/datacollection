

def get_kernel(s): 
    cnts = [] 
    kernel = [] 
    cur = 0 
    pos = cur + 1
    while cur < len(s): 
        if pos >= len(s) or s[pos] != s[cur]: 
            kernel += [s[cur]]
            cnts += [pos-cur]
            cur = pos
            pos += 1
        else: 
            pos += 1

    return kernel, cnts 

def possible(K): 
    for i in range(1, len(K)): 
        if K[i] != K[0]: 
            return False

    return True 

def col_min_cost(cols): 
    M = float('inf') 
    for pos in range(101): 
        m = sum([abs(pos-c) for c in cols]) 
        if m < M: 
            M = m 

    return M 

def min_cost(C): 
    n = len(C) 
    m = len(C[0]) 
    M = 0
    for c in range(m): 
        cols = [C[i][c] for i in range(n)] 
        M += col_min_cost(cols) 

    return M 

if __name__ == '__main__': 
    T = input() 
    for t in range(1, T+1): 
        n = input() 
        S = [raw_input() for _ in range(n)] 
        K = [] 
        C = [] 
        for s in S: 
            k, c = get_kernel(s) 
            K += [k] 
            C += [c] 
            
        if not possible(K): 
            print 'Case #%d: Fegla Won' %(t)
        else: 
            print 'Case #%d: %d' %(t, min_cost(C))

