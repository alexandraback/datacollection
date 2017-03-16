#!/usr/bin/python3.4

def unique(word):
    result = word[0]
    for i in range(1, len(word)):
        if word[i] != word[i-1]:
            result += word[i]
    return result

def convert(word):
    result = [1]
    for i in range(1, len(word)):
        if word[i] == word[i-1]:
            result[-1] += 1
        else:
            result += [1]
    return result

def partial(p):
    s = sorted(p)
    median = s[int(len(s) / 2)]
    return sum(abs(v - median) for v in p)

T = int(input())
for t in range(T):
    N = int(input())
    words = [input() for n in range(N)]

    sample = unique(words[0])
    if all([sample == unique(word) for word in words]):
        count = [convert(word) for word in words]
        partials = [partial(p) for p in zip(*count)]
        print("Case #{n}: {result}".format(n=t+1, result=sum(partials)))
    else:
        print("Case #{n}: Fegla Won".format(n=t+1))
