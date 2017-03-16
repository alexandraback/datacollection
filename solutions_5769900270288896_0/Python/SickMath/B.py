import itertools

f = open('small.in')
g = open('small.out', 'w')

T = int(f.readline()[:-1])

def weightCell(cell, cells) :
    r, c = cell
    return sum(cell in cells for cell in ((r-1, c), (r+1, c), (r, c-1), (r, c+1)))

for case in range(T) :
    R, C, N = map(int, f.readline()[:-1].split())
    allCells = set((r, c) for r in range(R) for c in range(C))
    res = R*(C-1) + (R-1)*C
    for comb in itertools.combinations(allCells, N) :
        comb_set = set(comb)
        res = min(res, sum(weightCell(cell, comb_set) for cell in comb_set) / 2)
    output = 'Case #' + str(case + 1) + ': ' + str(res)
    print output
    g.write(output + '\n')

f.close()
g.close()
