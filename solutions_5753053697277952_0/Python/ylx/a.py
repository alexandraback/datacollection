from sys import *
letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
f_i = open(argv[1])
f_o = open(argv[2], 'w')
cases = int(f_i.readline() [:-1])
for w in range(1, cases + 1):
    header = 'Case #' + str(w) + ': '
    f_i.readline()
    string = f_i.readline() [:-1]
    counts = [int(n) for n in string.split(' ')]
    current = counts
    plan = []
    while sum(current) > 3:
        sorted_curr = sorted(range(len(counts)), key = lambda x: current[x])
        if current[sorted_curr[-1]] - 1 > current[sorted_curr[-2]]:
            evacs = [sorted_curr[-1], sorted_curr[-1]]
        else:
            evacs = sorted_curr[-2:]
        plan.append(''.join([letters[n] for n in evacs]))
        current[evacs[0]] -= 1
        current[evacs[1]] -= 1
    if sum(current) == 3:
        if max(current) == 2:
            sorted_curr = sorted(range(len(counts)), key = lambda x: current[x])
            plan.append(letters[sorted_curr[-1]])
            plan.append(''.join([letters[n] for n in sorted_curr[-2:]]))
        else:
            sorted_curr = sorted(range(len(counts)), key = lambda x: current[x])
            plan.append(letters[sorted_curr[-1]])
            plan.append(''.join([letters[n] for n in sorted_curr[-3:-1]]))
    else:
        sorted_curr = sorted(range(len(counts)), key = lambda x: current[x])
        plan.append(''.join([letters[n] for n in sorted_curr[-2:]]))
    f_o.write(header + ' '.join(plan) + '\n')
f_o.close()
