import sys

def write(st):
    sys.stdout.write(st)
def writecase(i):
    if i == 0:
        print 'i is 0!!!!!!!!!!!!!!!!!'
    write("Case #%d: " % i)

f = open(sys.argv[1])
T = int(f.readline())

for t in range(1, T+1):
    board1 = []
    guess1 = int(f.readline())
    for i in range(4):
        line = f.readline()
        nums = [int(x) for x in line.split()]
        board1.append(nums)

    board2 = []
    guess2 = int(f.readline())
    for i in range(4):
        line = f.readline()
        nums = [int(x) for x in line.split()]
        board2.append(nums)

    inter = set(board1[guess1-1]).intersection(set(board2[guess2-1]))
#    print inter
    inter = list(inter)
    writecase(t)
    if len(inter) == 1:
        write('%d\n' % inter[0])
    elif len(inter) == 0:
        write('Volunteer cheated!\n')
    else:
        write('Bad magician!\n')

        
f.close()