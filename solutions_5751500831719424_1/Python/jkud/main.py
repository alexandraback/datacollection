#!/usr/bin/env python

def solve(N, words):
    new_words = []
    for word in words:
        new_word = []
        length = 0
        last_letter = None
        for letter in word:
            if letter == last_letter:
                length +=1
            else:
                if length:
                    new_word.append((last_letter, length))
                last_letter = letter
                length = 1
        new_word.append((last_letter, length))
        new_words.append(new_word)
    # Check length
    length = len(new_words[0])
    if any(len(new_words[i]) != length for i in range(N)):
        return 'Fegla Won'
    index = 0
    nmoves = 0
    for index in range(length):
        letter = new_words[0][index][0]
        if any(new_words[i][index][0] != letter for i in range(N)):
            return 'Fegla Won'
        lengths = [new_words[i][index][1] for i in range(N)]
        max_length = max(lengths)
        nmoves += min(sum(abs(l-i) for l in lengths) for i in range(1, max_length+1))
    return nmoves


T = int(raw_input().strip())
for t in range(T):
    N = int(raw_input().strip())
    words = [raw_input().strip() for _ in range(N)]
    print 'Case #%d: %s' % (t+1, solve(N, words))
