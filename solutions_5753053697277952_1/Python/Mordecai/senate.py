odd = lambda x: bool(x&1)
party = lambda i: chr(i + ord('A'))

def senate(P):
    el = []
    total = sum(P)
    N = len(P)
    if odd(total):
        over = total/2+1
        if over in P: x = P.index(over)
        else: x = 0
        P[x] -= 1
        el.append(party(x))
        total -= 1
    while total > 0:
        #print P, total
        half = total/2
        if half in P:
            x = P.index(half)
        else:
            x = filter(lambda i: P[i] != 0, range(N)).pop()
        y = filter(lambda i: i != x and P[i] != 0, range(N)).pop()
        el.append(party(x) + party(y))
        P[x] -= 1
        P[y] -= 1
        total -= 2
    return ' '.join(el)

def main():
    cases = int(raw_input())
    for case in range(1, cases+1):
        parties = int(raw_input())
        P = map(int, raw_input().split())
        print "Case #%i:" %case, senate(P)

if __name__ == '__main__':
    main()
