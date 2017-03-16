from string import ascii_uppercase

def majority(p):
    t = sum(p.values())
    return next(x for x, y in p.items() if y / t > 0.5)

for i in range(1, int(input()) + 1):
    input()
    p = dict(zip(ascii_uppercase, map(int, input().strip().split())))
    plan = []
    while any(p.values()):
        a = max(p.keys(), key=p.get)
        p[a] -= 1
        try:
            b = majority(p)
            p[b] -= 1
            a += b
            try:
                majority(p)
                print('TROUBLE TROUBLE')
            except:
                pass
        except:
            pass
        plan.append(a)
    print('Case #{}: {}'.format(i, ' '.join(plan)))
