#!/usr/bin/env python3.3
out_file = open('outputA.txt', 'w')

with open('A-small-attempt1.in') as in_file:
    n = int(in_file.readline())
    print(n)
    for i in range(n):
        r1 = int(in_file.readline())
        sq1 = [in_file.readline().strip().split() for j in range(4)]
        r2 = int(in_file.readline())
        sq2 = [in_file.readline().strip().split() for j in range(4)] 

  
        possibles = set(sq1[r1-1]) & set(sq2[r2-1])
        print(possibles)
        if len(possibles) > 1:
            out_file.write('Case #' + str(i+1) + ': Bad magician!\n')
        elif len(possibles) == 0:
            out_file.write('Case #' + str(i+1) + ': Volunteer cheated!\n')
        else:
            out_file.write('Case #' + str(i+1) + ': ' + possibles.pop() + '\n')

out_file.close()
