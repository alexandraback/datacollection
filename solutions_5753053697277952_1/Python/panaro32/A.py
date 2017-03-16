#!/usr/bin/env python3

def parse():
    _ = int(input())
    l = list(map(int, input().split()))
    return l

def solve(l):
    s = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    p = []
    while any(l):
        sl = sorted(enumerate(l), key=lambda x: x[1], reverse=True)
        k = l.count(sl[0][1])
        if not k%2:
            l[sl[0][0]] -= 1
            l[sl[1][0]] -= 1
            p.append(s[sl[0][0]]+s[sl[1][0]])
        else:
            l[sl[0][0]] -= 1
            p.append(s[sl[0][0]])
    return p

def main():
    for i in range(int(input())):
        l = parse()
        p = solve(l)
        print('Case #{}: {}'.format(i+1, ' '.join(p)))

if __name__ == '__main__': main()
