def len_tokens(w):
    c = 0
    current = w[0]
    l = []
    for i in w:
        if i == current:
            c += 1
        else:
            l.append(c)
            c = 1
            current = i
    l.append(c)
    return l

def remove_dupes(l):
    current = ''
    newl = []
    for i in l:
        if i != current:
            newl.append(i)
            current = i
    return newl

def felga_won(words):
    w1 = words[0]
    w2 = words[1]
    if set(w1) != set(w2):
        return True
    if remove_dupes(w1) != remove_dupes(w2):
        return True
    return False

cases = int(input())
for case in range(cases):
    num_words = int(input())
    words = []
    for i in range(num_words):
        words.append(input())
    if felga_won(words):
        print("Case #{}: Fegla Won".format(case+1)) #spelled right this time
        continue
    count = 0
    w1 = len_tokens(words[0])
    w2 = len_tokens(words[1])
    for i, j in zip(w1, w2):
        count += abs(i-j)
    print("Case #{}: {}".format(case+1, count))
