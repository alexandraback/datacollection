T=int(input())
for case_id in range(1,T+1):
    choose1 = int(input())
    for i in range(1,5):
        row = set(map(int,input().split()))
        if i == choose1:
            possible = row
    choose2 = int(input())
    for i in range(1,5):
        row = set(map(int,input().split()))
        if i == choose2:
            possible = possible.intersection(row)
    if len(possible) == 0:
        ans = 'Volunteer cheated!'
    elif len(possible) == 1:
        ans = str(possible.pop())
    else:
        ans = 'Bad magician!'
    
    print('Case #%d: %s' % (case_id, ans))
    import sys
    print('Case #%d: %s' % (case_id, ans), file=sys.stderr)
