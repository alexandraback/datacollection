def function(line):
    oper = []
    while any(line):
        most_id, almost_id = findTwoGreatest(line)
        if line[most_id] == 1 and line[almost_id] == 1 and sum(line) == 3:
            line[most_id] -= 1
            oper.append(chr(65+most_id))
            continue
        line[most_id] -= 1
        line[almost_id] -= 1
        if most_id > almost_id:
            oper.append(chr(65+almost_id) + chr(65+most_id))
        else:
            oper.append(chr(65+most_id) + chr(65+almost_id))
    return ' '.join(oper)



def findTwoGreatest(l):
    most = 0
    most_id = 0
    almost = 0
    almost_id = 0
    for i,x in enumerate(l):
        if x > most:
            almost = most
            almost_id = most_id
            most = x
            most_id = i
        elif x > almost:
            almost = x
            almost_id = i
    return (most_id, almost_id)

# MAIN
# input like this:
# T
# N      -----> Case #1: m
# 1 ... N
# N      -----> Case #2: m
# 1 ... N
with open('input.txt', 'r') as f:
    raw = f.readlines()
    T = int(raw[0])
    c = 1
    for case in range(T):
        N = int(raw[c])
        c += 1
        line = list(map(int, raw[c].split()))
        c += 1
        print('Case #' + str(case+1) + ': ' + str(function(line)))
