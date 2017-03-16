T = int(raw_input())

for index in xrange(T):
    R, C, N = map(int, raw_input().split(' '))
    if N * 2 <= R * C + 1:
        result = 0
    elif R == 1 or C == 1:
        length = max(R, C)
        if length % 2 == 0:
            result = 1 + 2 * max(0, N - length/2 - 1)
        else:
            result_1 = 2 * (N - (length + 1) / 2)
            result_2 = min(2, N - length/2) + 2 * max(0, N - length/2 - 2)
            result = min(result_1, result_2)
        
    else:
        result_1, result_2 = 0, 0
        remaining = N - (R * C + 1) / 2
        if R * C % 2 == 0:
            result_1 += 2 * min(2, remaining)
            remaining -= 2
        if remaining > 0:
            max_row = (R - 1) / 2
            max_col = (C - 1) / 2
            max_edge = 2 * (max_col + max_row)
            if (R % 2 == 1 or C % 2 == 1) and R * C % 2 == 0:
                max_edge -= 1
            result_1 += 3 * min(max_edge, remaining)
            remaining -= max_edge
        result_1 += 4 * max(0, remaining)

        remaining = N - (R * C) / 2        
        if R * C % 2 == 1:
            result_2 += 2 * min(4, remaining)
            remaining -= 4
        if remaining > 0:
            max_row = (R - 2) / 2
            max_col = (C - 2) / 2
            max_edge = 2 * (max_col + max_row)
            result_2 += 3 * min(max_edge, remaining)
            remaining -= max_edge            
        result_2 += 4 * max(0, remaining)
        result =  min(result_1, result_2)
        
        
    print "Case #%d: %d" % ((index+1), result)#, R, C, N)
