def main():
    with open('test.out', 'w') as g:
        with open('test.in') as f:
            T = int(f.readline())
            for t in range(T):
                N = int(f.readline().strip())
                P = list(map(int, f.readline().strip().split()))
                answer_str = 'Case #{}: '.format(t + 1) + str(answer(P))
                print(answer_str)
                g.write(answer_str)
                g.write('\n')


def party(i):
    return chr(ord('A') + i)


def answer(P):
    if sum(P) == 0:
        return ''
    r = ''
    if sum(P) <= 2:
        for i, e in enumerate(P):
            while e > 0:
                r += party(i)
                e -= 1
        return r
    r += party(argmax(P))
    P = shave_max(P)
    if max_args(P) % 2 > 0:
        r += party(argmax(P))
        P = shave_max(P)
    return r + ' ' + answer(P)


def argmax(P):
    for i, e in enumerate(P):
        if e == max(P):
            return i


def shave_max(P):
    for i, e in enumerate(P):
        if e == max(P):
            P[i] -= 1
            break
    return P


def max_args(P):
    r = 0
    for e in P:
        if e == max(P):
            r += 1
    return r


if __name__ == '__main__':
    main()