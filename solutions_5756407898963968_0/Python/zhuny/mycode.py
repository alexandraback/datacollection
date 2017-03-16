def do():
    count = input()
    for i in xrange(count):
        print "Case #%d:"%(i+1),
        calculate()

def calculate():
    row1 = input()-1
    L1 = [map(int,raw_input().split()) for i in xrange(4)][row1]
    row2 = input()-1
    L2 = [map(int,raw_input().split()) for i in xrange(4)][row2]
    
    L1,L2 = set(L1),set(L2)
    
    L3 = L1.intersection(L2)
    if len(L3) == 1:
        print L3.pop()
    elif len(L3) > 1:
        print "Bad magician!"
    else:
        print "Volunteer cheated!"


if __name__ == '__main__':
    do()
