
T = input() 


def bitmask_to_row(mask, C): 
    cnt = 0
    row = [0] * C
    for i in range(C): 
        if mask & (1 << i): 
            row[i] = 1
            cnt += 1

    return cnt, row

def bitmask_to_grid(mask, R, C, N): 
    G = []
    cnt = 0
    for _ in range(R): 
        n, row = bitmask_to_row(mask, C)
        G.append(row)
        cnt += n
        mask = mask >> C
    
    if cnt == N:
        return G
    return None

def count_people(G):
    return sum([r.count(1) for r in G])

def get_val(G, R, C): 
    cnt = 0
    for r in range(R): 
        for c in range(C): 
            x = r
            y = c
            if G[x][y] == 1:
                if y + 1 < C and G[x][y+1] == 1: 
                    cnt += 1
                if x + 1 < R and G[x+1][y] == 1:
                    cnt += 1
    return cnt

for t in range(1, T+1):

    R, C, N = map(int, raw_input().split()) 
    min_val = N * 8

    for i in range(R*C << 16): 
        G = bitmask_to_grid(i, R, C, N)
        if G is None:
            continue
        if count_people(G) == N:
            val = get_val(G, R, C)
            if val < min_val:
                min_val = val

    print 'Case #%d:' %t, min_val

