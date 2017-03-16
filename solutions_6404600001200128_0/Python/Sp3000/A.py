def first(mushrooms):
    total = 0
    
    for i in range(len(mushrooms) - 1):
        if mushrooms[i+1] < mushrooms[i]:
            total += mushrooms[i] - mushrooms[i+1] 

    return total


def second(mushrooms):
    max_rate = max(mushrooms[i] - mushrooms[i+1]
                   for i in range(len(mushrooms) - 1))

    total = 0

    for i in range(len(mushrooms) - 1):
        total += min(max_rate, mushrooms[i])

    return total

with open("A-small-attempt0.in") as infile:
    with open("A.out", "w") as outfile:
        ncases = int(next(infile))

        for case in range(1, ncases + 1):
            N = int(next(infile))
            mushrooms = list(map(int, next(infile).split()))

            print("Case #{}: {} {}".format(case, first(mushrooms), second(mushrooms)), file=outfile)
