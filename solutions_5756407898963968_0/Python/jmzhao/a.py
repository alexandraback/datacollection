import sys

def printerr(*v):
    print(*v, file=sys.stderr)

def prework(argv):
    '''do something according to argv,
    return a message describing what have been done.'''
    
    return "nothing"

def once():
    r1 = int(input())
    g1 = [[int(x) for x in input().split()] for _ in range(4)]
    r2 = int(input())
    g2 = [[int(x) for x in input().split()] for _ in range(4)]

    s = set(g1[r1-1]).intersection(g2[r2-1])
    printerr(s)
    
    if len(s) > 1 : 
        return  "Bad magician!"
    elif len(s) < 1 :
        return "Volunteer cheated!"
    else :
        return s.pop()            

def ans2str(ans):
    return str(ans)

def main():
    TT = int(input())
    for tt in range(1,TT+1):
        printerr("coping Case %d.."%(tt))
        ans = once()
        print("Case #%d: %s"%(tt, ans2str(ans)))

if __name__ == '__main__' :
    msg = prework(sys.argv)
    print("prework down with", msg, file=sys.stderr)
    main()
