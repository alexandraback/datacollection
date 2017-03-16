import sys



def solve(firstrow, firstlayout, secondrow, secondlayout):
    return set(firstlayout[firstrow - 1]) & set(secondlayout[secondrow - 1])

def read_layout():
    return [[int(x) for x in input().split()] for i in range(4)]

def read_one():
    firstrow = int(input())
    firstlayout = read_layout()
    secondrow = int(input())
    secondlayout = read_layout()
    return (firstrow, firstlayout, secondrow, secondlayout)


def main():
    ncases = int(input())
    for i in range(1, ncases + 1):
        solution = solve(*read_one())
        print('Case #{}: '.format(i), end='')
        if not solution:
            print("Volunteer cheated!")
        elif len(solution) > 1:
            print("Bad magician!")
        else:
            print(next(iter(solution)))

main()
