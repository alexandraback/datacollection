import sys


input = open('///Users/Zetilov/Downloads/B-small-attempt1.in.txt', 'r')
output = open('output.txt', 'w')


#input = sys.stdin
#output = sys.stdout

T = int(input.readline())
for z in range(T):
    print(z)
    b, n = map(int, input.readline().split())
    v = [int(i) for i in input.readline().split()]
    #if z != 101:
        #continue
    fr = 10 ** 18
    rd = 0
    for j in v:
        L, R = -1, 10 ** 18
        while R - L > 1:
            M = (L + R) // 2
            s = 0
            d = 0
            for i in v:
                s += M * j // i + 1
                if M * j % i == 0:
                    d += 1
                    s -= 1
            if s + d >= n:
                if M * j < fr:
                    fr = M * j
                    rd = n - s - 1
                R = M
            else:
                L = M
    R = fr
    #print(fr)
    for i in range(b):
        if R % v[i] == 0:
            if rd == 0:
                print('Case #', z + 1, ': ', i + 1, sep = '', file = output)
                break
            else:
                rd -= 1
    else:
        print(179)

input.close()
output.close()