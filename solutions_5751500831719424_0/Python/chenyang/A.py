def split_unique_chars(word):
    prev = ""
    chars, counts = [], []
    for i in word:
        if i != prev:
            chars.append(i)
            counts.append(1)
            prev = i
        else:
            counts[-1] += 1
    return "".join(chars), counts


for t in range(input()):
    n = input()
    strings = [raw_input() for _ in range(n)]
    no_dups, counts = zip(*map(split_unique_chars, strings))

    if len(set(no_dups)) > 1:
        answer = "Fegla Won"
    else:
        uniqs = zip(*counts)
        count = 0
        for u in uniqs:
            u = sorted(u)
            median = u[len(u) / 2]
            count += sum(map(lambda x: abs(x - median), u))
        answer = str(count)
    print "Case #{}: {}".format(t+1, answer)
