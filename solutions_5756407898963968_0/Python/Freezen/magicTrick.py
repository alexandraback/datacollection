import sys

def main():
    T = int(sys.stdin.readline())
    case = 1
    while T > 0:
        r1 = int(sys.stdin.readline())
        for i in range(4):
            l = sys.stdin.readline().split()
            if i+1 == r1:
                s1 = set(l)
        r2 = int(sys.stdin.readline())
        for i in range(4):
            l = sys.stdin.readline().split()
            if i+1 == r2:
                s2 = set(l)
        sr = s1.intersection(s2)
        if len(sr) == 1:
            print 'Case #'+str(case)+': '+sr.pop()
        elif len(sr) > 1:
            print 'Case #'+str(case)+': Bad magician!'
        else:
            print 'Case #'+str(case)+': Volunteer cheated!'
        T -= 1
        case += 1

if __name__ == '__main__':
    main()
