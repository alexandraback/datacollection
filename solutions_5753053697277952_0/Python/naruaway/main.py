def argmax(xs):
    current_max = -1
    current_i = -1
    for i, x in enumerate(xs):
        if current_max < x:
            current_i = i
            current_max = x
    return current_i


def num2str(num):
    return chr(ord('A') + num)

T = int(input())
for t in range(T):
    N = int(input())
    P = [int(i) for i in input().split()]
    def logic():
        while True:
            num_parties = sum(map(lambda i: 1 if i != 0 else 0, P))
            if num_parties == 0:
                break
            if num_parties == 2:
                indicies = [n for n in range(N) if P[n] != 0]
                for i in indicies:
                    P[i] -= 1
                yield ''.join(map(num2str, indicies))
            else:
                i = argmax(P)
                P[i] -= 1
                yield num2str(i)
    print('Case #{}: {}'.format(t + 1, ' '.join(logic())))
