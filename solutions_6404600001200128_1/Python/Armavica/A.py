#! /usr/bin/python3

def load_file(chemin):
    def parse_input(f): # TODO
        n = int(f.readline())
        line = [int(n) for n in f.readline().split()]
        return line

    from os.path import isfile
    with open(chemin, 'r') as file:
        for _ in range(int(file.readline())):
            yield parse_input(file)
        file.close()

def solve(l): # TODO
    m1 = 0
    p = l[0]
    for m in l[1:]:
        if m < p:
            m1 += p-m
        p = m
    
    minrate = 0
    p = l[0]
    for m in l[1:]:
        if p - minrate > m:
            minrate = p-m
        p = m
    m2 = 0
    for m in l[:-1]:
        m2 += min(minrate,m)

    return str(m1)+" "+str(m2)


from sys import argv

for (i, case) in enumerate(load_file(argv[1])):
    print("Case #" + str(i+1) + ":", solve(case))

