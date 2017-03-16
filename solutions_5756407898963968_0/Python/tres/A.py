def possibleCards():
    row = int(input())
    rows = [set(map(int, input().split())) for _ in range(4)]
    return rows[row-1]

for t in range(1,int(input())+1):
    possibilities = possibleCards() & possibleCards()
    if not possibilities:
        result = 'Volunteer cheated!'
    elif len(possibilities) == 1:
        result = possibilities.pop()
    else:
        result = 'Bad magician!'
    print('Case #{0}: {1}'.format(t, result))
