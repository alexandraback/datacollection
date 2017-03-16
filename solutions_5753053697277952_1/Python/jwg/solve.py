#google code jam I/O template
import string
import collections
def solve(n, ct):
    uppers = string.ascii_uppercase
    counts = {}
    
    counter = collections.Counter()
    result = []
    for i in range(n):
        counter[uppers[i]] += ct[i]

    while len(counter) > 2:
        highest = counter.most_common(1)[0][0]
        counter[highest] -= 1
        if counter[highest] == 0:
            counter.pop(highest)
        result.append(highest)

    while len(counter) > 1:
        highest = counter.most_common(2)[0][0]
        secondHighest = counter.most_common(2)[1][0]
        counter[highest] -= 1
        counter[secondHighest] -= 1
        if counter[highest] == 0:
            counter.pop(highest)
        if counter[secondHighest] == 0:
            counter.pop(secondHighest)
        result.append(highest+secondHighest)

    if len(counter) == 0:
        return result

    left = counter.most_common(1)[0]
    result = result + [left[0] for _ in range(left[1])]
    return result







numCases = input()
for caseNum in range(1, numCases+1):
    #read single-line input
    n = input()
    ct = map(int, raw_input().split(" "))
    ans = solve(n, ct)
    print "Case #%d: %s" % (caseNum, " ".join(ans))






