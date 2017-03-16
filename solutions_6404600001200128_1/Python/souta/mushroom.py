import math


fin = open('A-small-attempt0.in','r')
fout = open('output.txt','w')
t = int(fin.readline())
for count in range(1, t + 1):
    n = int(fin.readline())
    m = [int(i) for i in fin.readline().split()]
    result1 = 0
    speed = 0
    for i in range(0, n - 1):
        if m[i] > m[i + 1]:
            result1 += m[i] - m[i + 1]
        if speed < m[i] - m[i + 1]:
            speed = m[i] - m[i + 1]
    result2 = 0
    for i in range(0, n - 1):
        if m[i] < speed:
            result2 += m[i]
        else:
            result2 += speed
    fout.write('Case #'+str(count)+': '+ str(result1) + ' ' + str(result2) +'\n')
fin.close()
fout.close()
