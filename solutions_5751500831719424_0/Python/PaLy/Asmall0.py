def remove_identical(ss):
    res = []
    for s in ss:
        res.append(s[0])
        for i in range(1, len(s)):
            if s[i] != s[i - 1]:
                res[-1] += s[i]
    return res


def to_numbers(ss):
    res = []
    for s in ss:
        res.append([1])
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                res[-1][-1] += 1
            else:
                res[-1].append(1)
    return res


def main():
    n = int(input())
    ss = [input() for _ in range(n)]
    ss2 = remove_identical(ss)
    if len(set(ss2)) != 1:
        return "Fegla Won"
    else:
        res = 0
        ns = to_numbers(ss)
        for coli in range(len(ns[0])):
            a = []
            for row in ns:
                a.append(row[coli])
            a.sort()
            med = a[len(ns) // 2]
            for x in a:
                res += abs(med - x)
    return str(res)


if __name__ == '__main__':
    t = int(input())
    for ti in range(1, t + 1):
        print("Case #" + str(ti) + ": " + main())
