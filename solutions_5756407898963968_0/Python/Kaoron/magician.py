import fileinput

import itertools as it


lines = fileinput.input()
nb_cases = int(lines.next())


def print_result(n, res):
    print 'Case #%d: %s'%(n, res)

for i in range(1, nb_cases+1):
    spot1 = int(lines.next())-1
    set1 = set(list(it.islice(lines, 4))[spot1].strip().split())
    spot2 = int(lines.next())-1
    set2 = set(list(it.islice(lines, 4))[spot2].strip().split())
    res = set1.intersection(set2)
    #print res



    if len(res)==1 : print_result(i, list(res)[0])
    elif len(res)>1 : print_result(i, 'Bad magician!')
    else : print_result(i, 'Volunteer cheated!')

