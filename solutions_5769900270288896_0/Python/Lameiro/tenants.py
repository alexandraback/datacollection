def read_list_of(numtype):
    return map(numtype, raw_input().split())

def solution_number(matrix):
    n = 0
    for i in xrange(len(matrix)):
        for j in xrange(len(matrix[i])):
            if matrix[i][j] == 1:
                n += 2**(i*len(matrix)+j)

    return n

def happiness(matrix):
    c = 0
    for line in matrix:
        for j in xrange(len(line)-1):
            if line[j] == 1 and line[j+1] == 1:
                c += 1

    for i in xrange(len(matrix)-1):
        for j in xrange(len(matrix[i])):
            if matrix[i][j] == 1 and matrix[i+1][j] == 1:
                c += 1

    return c


def solve(r, c, n):
    M = [[0] * c for _ in xrange(r)]

    to_solve = [(M, 0)]
    computing = set()

    all_solutions = []

    while len(to_solve) > 0:
        a, level = to_solve[0]
        del to_solve[0]

        if level == n:
            all_solutions.append(a)
        else:
            for i in xrange(r):
                for j in xrange(c):
                    if a[i][j] == 0:
                        #print 'add'
                        newM = [x[:] for x in a]
                        newM[i][j] = 1

                        sn = solution_number(newM)
                        if sn not in computing:
                            to_solve.append((newM, level+1))
                            computing.add(sn)

    #print 'sort'
    all_solutions.sort(key=lambda s: happiness(s))
    return happiness(all_solutions[0])

def main():
    for case_number in xrange(int(raw_input())):
        r, c, n = read_list_of(int)
        result = solve(r,c,n)

        print 'Case #%d: %d' % (case_number+1, result)

#main()

print solve(2,6, 0)

# print solve(2,2, 4) == 4
# print solve(2,2, 3) == 2
# print solve(3,3, 4) == 0
# print solve(3,3, 5) == 0
# print solve(3,3, 8) == 8
# print solve(3,3, 9) == 12
# print solve(5,2, 0) == 0
# print solve(2,3, 5) == 4

#print solve(3,3, 8)
#print solve([1,2,3,4])
