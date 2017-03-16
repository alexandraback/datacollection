al = list('ABCDEFGHIJKLMNOPQRSTUVWXYZ')

for t in range(1, int(input())+1):
    n = int(input()) # parties
    p = list(map(int, input().split())) # senators of parties
    plan = []
    parties = sorted(list(zip(p, al)), reverse=True)
    while parties[0][0] > parties[1][0]:
        plan.append(parties[0][1])
        parties[0] = (parties[0][0] - 1, parties[0][1])
    for i in range(2, n):
        plan = plan + [parties[i][1]] * parties[i][0]
    plan = plan + [parties[0][1] + parties[1][1]] * parties[0][0]
    print('Case #' + str(t) + ': ' + ' '.join(plan))
