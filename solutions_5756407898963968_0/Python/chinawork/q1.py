__author__ = 'cni'

file_name = 'A-small-attempt1.in.txt'
f = open(file_name)
lines = f.readlines()
f.close()

def ans(ans1, ans2, t1, t2):
    pos1 = set(t1[ans1 - 1])
    pos2 = set(t2[ans2 - 1])

    res = pos1.intersection(pos2)

    if len(res) == 1:
        return str(res.pop())
    elif len(res) > 1:
        return 'Bad magician!'
    else:
        return 'Volunteer cheated!'

case_num = int(lines[0])
idx = 1

f = open('out.txt', 'w')
for i in xrange(case_num):
    ans1 = int(lines[idx])
    idx += 1

    t1 = [[int(j) for j in line.split()] for line in lines[idx : idx + 4]]
    idx += 4

    ans2 = int(lines[idx])
    idx += 1

    t2 = [[int(j) for j in line.split()] for line in lines[idx : idx + 4]]
    idx += 4

    res = ans(ans1, ans2, t1, t2)

    f.write('Case #%d: %s\n' % (i + 1, res))
f.close()
