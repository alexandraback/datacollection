import codejam as gcj
import codejam.iterators as itr

def compressed(s):
    c = s[0]
    for a, b in itr.window(s, 2):
        if a != b:
            c += b
    return c

def convert(s, pattern):
    counts = [1] * len(pattern)
    i = 0
    for a, b in itr.window(s, 2):
        if a == b:
            counts[i] += 1
        else:
            i += 1
    return counts

T = gcj.read_input('i')
for t in range(T):
    N, words = gcj.read_input('i->', 's')
    unique_compressed_words = set(map(compressed, words))
    if len(unique_compressed_words) == 1:
        pattern = unique_compressed_words.pop()
        words = map(lambda s: convert(s, pattern), words)
        answer = 0

        for i in range(len(pattern)):
            chunks = list(sorted(word[i] for word in words))
            best_cost = 10**9
            for target in range(chunks[0], chunks[-1] + 1):
                costs = map(lambda x: abs(x - target), chunks)
                best_cost = min(best_cost, sum(costs))
            answer += best_cost
    else:
        answer = 'Fegla Won'

    print 'Case #%i:' % (t + 1), answer