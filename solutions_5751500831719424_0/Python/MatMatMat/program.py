def convertToLsts(s):
    last = s[0]
    count = 1
    chrs = []
    counts = []
    for i in range(1, len(s)):
        if last == s[i]:
            count += 1
        else:
            chrs.append(last)
            counts.append(count)
            count = 1
            last = s[i]

    chrs.append(last)
    counts.append(count)

    return tuple(chrs), counts

def solve(strings):
    arrs = [convertToLsts(s) for s in strings]
    chrArrs = [arr[0] for arr in arrs]
    countArrs = [arr[1] for arr in arrs]

    if not all(arr == chrArrs[0] for arr in chrArrs):
        return "Fegla Won"

    total = 0
    for i in range(len(countArrs[0])):
        theseCounts = [arr[i] for arr in countArrs]
        mn = 10**10
        for n in theseCounts:
            s = sum(int(abs(x - n)) for x in theseCounts)
            if s < mn:
                mn = s
        total += mn

    return total

for t in range(1, int(input())+1):
    strings = [input() for i in range(int(input()))]
    print("Case #" + str(t) + ": " + str(solve(strings)))
