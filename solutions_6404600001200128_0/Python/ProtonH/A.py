import sys

args = sys.argv

if len(args) == 2:
    f = open(args[1],'r')
    of = open('output.txt','w')
    breakFlag = False
    num = 0
    numCalculated = False
    i = -1
    while not breakFlag:
        l = f.readline()
        if not numCalculated:
            num = int(l.strip())
            numCalculated = True
            i = 0
        elif i < num:
            l = l.strip()
            l1 = f.readline()
            N = int(l)
            m = []
            l1s = l1.split(' ')
            for x in l1s:
                m.append(int(x))
            case1ans = 0
            case2ans = 0
            print(m)
            for x in range(N-1):
                if m[x] > m[x+1]:
                    case1ans = case1ans + (m[x] - m[x+1])
            maxEat = 0
            maxEatI = 0
            for x in range(N-1):
                if m[x] > m[x+1]:
                    t = m[x] - m[x+1]
                    if t > maxEat:
                        maxEat = t
            rate = maxEat/10
            print(m)
            print('Max Eat : ' + str(maxEat))
            for x in range(N-1):
                if maxEat <= m[x]:
                    print('Eating 1 : ' + str(maxEat))
                    case2ans = case2ans + maxEat
                else:
                    print('Eating 2 : ' + str(m[x]))
                    case2ans = case2ans + m[x]
            of.write('Case #'+str(i+1)+': ' + str(case1ans) + ' ' + str(case2ans) +'\n')
            print('Case #'+str(i+1)+': ' + str(case1ans) + ' ' + str(case2ans))
            i = i + 1
        else:
            breakFlag = True
    of.flush()
    of.close()
    f.close()

sys.exit()


"""of.write('Case #'+str(i+1)+': NO\n')
print('Case #'+str(i+1)+': NO')"""
