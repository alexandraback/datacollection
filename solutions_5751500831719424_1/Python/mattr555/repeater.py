from statistics import median

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

def fegla_won(words):
    dupes = None 
    for i in words:
        if dupes is None:
            dupes = remove_dupes(i)
        elif remove_dupes(i) != dupes:
            return True
    return False

cases = int(input())
for case in range(cases):
    num_words = int(input())
    words = []
    for i in range(num_words):
        words.append(input())
    if fegla_won(words):
        print("Case #{}: Fegla Won".format(case+1)) #spelled right this time
        continue
    count = 0
    tokens = []
    for i in words:
        tokens.append(len_tokens(i))
    for i in zip(*tokens):
        mid = int(median(i))
        for j in i:
            count += abs(j-mid)
    print("Case #{}: {}".format(case+1, count))
