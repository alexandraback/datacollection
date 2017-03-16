for TC in range(1, int(raw_input()) + 1):
    n = int(raw_input())
    strings = []
    
    for s in range(n):
        strings.append(raw_input())
    
    prev = ""
    unique = ""
    for cur in strings[0]:
        if cur != prev:
            unique += cur
            prev = cur
            
    size = []
    for i in range(n):
        size.append([0] * len(unique))
    
    impossible = False
    for i, s in enumerate(strings):
        prev = ""
        unique_index = 0
        size_index = 0
        for cur in s:
            if cur != prev:
                if unique_index < len(unique):
                    if cur != unique[unique_index]:
                        impossible = True
                    unique_index += 1
                    
                    if prev:
                        size_index += 1
                    prev = cur
                else:
                    impossible = True
            size[i][size_index] += 1
            if impossible:
                break
        if unique_index != len(unique):
            impossible = True
        if impossible:
            break
    
    if impossible:
        print "Case #%d: Fegla Won" % TC
        continue
    
    ans = 0
    for k in range(len(unique)):
        group_min = 99999
        for i in range(n):
            moves = 0
            for j in range(n):
                if i == j:
                    continue
                moves += abs(size[i][k] - size[j][k])
            if moves < group_min:
                group_min = moves
        ans += group_min
    print "Case #%d: %d" % (TC, ans)
