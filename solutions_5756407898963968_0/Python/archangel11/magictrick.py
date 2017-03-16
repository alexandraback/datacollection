bad = "Bad magician!"
cheat = "Volunteer cheated!"

def solve(f):
    def readGrid():
        grid = []
        for i in xrange(4):
            grid.append(map(int, f.readline().split()))
        return grid

    n1 = int(f.readline()) - 1
    arr1 = readGrid()
    n2 = int(f.readline()) - 1
    arr2 = readGrid()

    output = ''

    set1 = set(arr1[n1])
    set2 = set(arr2[n2])
    possible = set1.intersection(set2)
    if len(possible) == 1:
        output = possible.pop()
    elif len(possible) > 1:
        output = bad
    else:
        output = cheat

    return output

