import string
fname = 'C:\Users\itocar\Downloads\A-small-attempt0.in'

f = open(fname)

ln = f.readlines()

t = int(ln[0])

case_num = 1
for l in ln[2::2]:
    state = [int(x) for x in l.split()]
    res = []
    s = sum(state)
    while s > 0:
        mx = max(state)
        mx_ind = state.index(mx)
        state[mx_ind] -= 1
        ss = sum(state)
        flag = True
        oi = 0
        for q in state:
            if (q >= ss/2 + 1):
                flag = False
                oi = state.index(q)
        if flag:
            res.append(string.uppercase[mx_ind])
            s -=1
        else:
            res.append(string.uppercase[mx_ind] + string.uppercase[oi])
            state[oi] -=1
            s -=2
    print "Case #" +  str(case_num) + ": " + " ".join(res)
    case_num += 1