import sys

f = open('A-large.in')
f_out = open('A-large.out', 'w')

T = int(f.readline())
for k in range(T):
    l = int(f.readline())
    line = f.readline().split()
    a = [int(x) for x in line]
    m_diff = 0
    sum1 = 0
    for i in range(0, l-1):
        if a[i]-a[i+1]>0:
            sum1 += a[i]-a[i+1]
        if a[i]-a[i+1]>m_diff:
            m_diff = a[i]-a[i+1]
    sum2 = 0
    for i in range(0, l-1):
        if a[i]<m_diff:
            sum2 += a[i]
        else:
            sum2 += m_diff
    f_out.write('Case #{0}: {1} {2}\n'.format(k+1, sum1, sum2))

f.close()
f_out.close()
