#!/usr/bin/python
import sys

f=open("test.in", "r")
nb_tests = int(f.readline())

def count(dist) :
    c = 0
    for i in dist:
        if i != 0 :
            c+=1
    return c

def find_max(dist, only_non_zero=False) :
    m_j = 0
    m_i = -1
    for i,j in enumerate(dist):
        if j > m_j :
            m_j = j
            m_i = i
    if only_non_zero and m_j == 1 :
        return ""
    dist[m_i]-=1;
    return chr(ord("A")+m_i)

for i in range(nb_tests):
    sys.stderr.write("NB part %s\n" % f.readline())
    dist = f.readline()
    dist = list(map(int, dist.split(" ")))
    sys.stderr.write(str(dist) + "\n")

    sys.stdout.write("Case #%d: " % (i+1))
    while count(dist) > 0 :
        ans=find_max(dist)
        ans+=find_max(dist, count(dist) == 2)
        sys.stdout.write(ans + " ")
    sys.stdout.write("\n")
