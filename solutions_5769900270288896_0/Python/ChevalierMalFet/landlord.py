inputF = open('B-small-attempt0.in', 'r')
output = open('B-small-attempt0.out', 'w')

import itertools

numCases = int(inputF.readline())

# Brute Force method
def evalAssn(r, c, assn):
    count = 0
    for i in range(len(assn)):
        if assn[i] == '1':
            if i%c != 0 and assn[i-1] == '1':
                count += 1
            if i%c != c-1 and assn[i+1] == '1':
                count += 1
            if i>=c and assn[i-c] == '1':
                count += 1
            if i < (r-1)*c and assn[i+c] == '1':
                count += 1
    return count/2

def allAssns(r,c,n):
    assns = ["".join(seq) for seq in itertools.product("01", repeat=r*c)]
    assns = [i for i in assns if i.count('1') == n]
    return assns

for i in range(numCases):
    line = inputF.readline().split()
    r = int(line[0])
    c = int(line[1])
    n = int(line[2])

    assns = allAssns(r,c,n)
    minAssn = r*c*4
    for assn in assns:
        x = evalAssn(r,c,assn)
        if x < minAssn:
            minAssn = x
        if minAssn == 0:
            break
    

    output.write('Case #' + str(i+1) + ': ')
    output.write(str(minAssn) + '\n')




inputF.close()
output.close()
