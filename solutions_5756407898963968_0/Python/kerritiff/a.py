
def get():
    r = int(raw_input())
    for i in xrange(1, 5):
        x = map(int, raw_input().split())
        if i == r:
            ans = set(x)
    return ans

def solve():
    ans = get() & get()
    if len(ans) == 1:
        return list(ans)[0]
    if len(ans) > 1:
        return 'Bad magician!' 
    else:
        return 'Volunteer cheated!'

def main():
    t = int(raw_input())
    for i in xrange(1, t+1):
        print 'Case #%s: %s' % (i, solve())

if __name__ == '__main__':
    main()
