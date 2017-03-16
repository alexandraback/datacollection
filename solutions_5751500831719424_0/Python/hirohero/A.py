f = open('input.txt','r').read()
test = int(f.readline())

for i in range(test):
    n, l = f.readline().split()
    n, l = int(n), int(l)

    outlets = f.readline().split()
    devices = f.readline().split()

    dem1 = [0 for t in range(l)]
    dem2 = [0 for t in range(l)]

    for outlet in outlets:
        for j in range(len(outlet)):
            if outlet[j] == '1':
                dem1[j] += 1
                
    for device in devices:
        for j in range(len(device)):
            if device[j] == '1':
                dem2[j] += 1

    res = 0
    for j in range(l):
        if dem1[j] == dem2[j]: continue
        if dem1[j] + dem2[j] == n:
            res += 1
        else:
            res = -1
            break

    s = 'Case #' + str(i + 1) + ': '
    if res == -1: s = s + 'NOT POSSIBLE'
    else:
        s = s + str(res)
    print s
