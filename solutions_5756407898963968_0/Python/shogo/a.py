T = int(raw_input())

for i in range(T):
    ans1 = int(raw_input())
    cards1 = [set(raw_input().split()) for _ in range(4)]
    ans2 = int(raw_input())
    cards2 = [set(raw_input().split()) for _ in range(4)]
    ans = cards1[ans1-1] & cards2[ans2-1]
    print 'Case #%d:' % (i + 1),
    if len(ans)==0:
        print 'Volunteer cheated!'
    elif len(ans)==1:
        print ans.pop()
    else:
        print 'Bad magician!'
