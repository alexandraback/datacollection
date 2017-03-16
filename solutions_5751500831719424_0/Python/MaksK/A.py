import numpy as np

asdf = int(raw_input())
for asd in xrange(asdf):
    print "Case #%d:" % (asd+1),
    n = int(raw_input())
    sizes = []
    chars = None
    possible = True
    for j in range(n):
        line = raw_input()
        char_list = [line[0]]
        len_list = [1]
        for i in range(1, len(line)):
            if line[i] != line[i - 1]:
                char_list.append(line[i])
                len_list.append(1)
            else:
                len_list[-1] += 1
        if chars and chars != char_list:
            possible = False
            break
        chars = char_list
        sizes.append(len_list)

    if not possible:
        print "Fegla Won"
    else:
        #print sizes
        num = len(sizes[0])
        moves = 0
        for c in range(num):
            min_moves = float("inf")
            for i in range(n):
                temp_moves = 0
                for j in range(n):
                    temp_moves += abs(sizes[i][c] - sizes[j][c])
                min_moves = min(min_moves, temp_moves)
            moves += min_moves

        print moves


