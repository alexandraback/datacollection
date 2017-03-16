num_tests = int(input())
for n in range(num_tests):
    num_l = int(input())
    freqs = list(map(int, input().split()))
    letters = {letter: freq for letter, freq in zip([chr(x) for x in range(65, 65 + num_l)], freqs)}
    result = []
    while sum(letters.values()) >= 2:
        res = ''
        r = max(letters, key = lambda x: letters[x])
        letters[r] -= 1
        if letters[r] == 0:
            del letters[r]
        res += r
        if all([l == 1 for l in letters.values()]) and len(letters) == 2:
            pass
        else:
            r = max(letters, key = lambda x: letters[x])
            letters[r] -= 1
            if letters[r] == 0:
                del letters[r]
            res += r
        result.append(res)
    print('Case #{}: {}'.format(n + 1, ' '.join(result)))
