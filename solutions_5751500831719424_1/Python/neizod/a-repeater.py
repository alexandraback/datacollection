def transpose(matrix):
    return [list(vector) for vector in zip(*matrix)]


def identity(word):
    b, l = '', []
    for c in word:
        if not b:
            b, i = c, 0
        elif b == c:
            i += 1
        else:
            l += [(b, i)]
            b, i = c, 0
    else:
        l += [(b, i)]
    return l


def magic(words):
    process = [identity(word) for word in words]
    if len(set(''.join(k for k, _ in idword) for idword in process)) > 1:
        return None
    return sum(min(sum(abs(i-x) for i in l) for x in range(min(l), max(l)+1)) for l in transpose([v for _, v in idword] for idword in process))


for case in range(int(input())):
    words = [input() for _ in range(int(input()))]
    answer = magic(words)
    if answer is None:
        answer = 'Fegla Won'
    print('Case #{}: {}'.format(case+1, answer))
