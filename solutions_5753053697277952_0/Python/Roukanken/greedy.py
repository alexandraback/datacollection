def get(x):
    return chr(ord("A") + x)

def work():
    input()
    data = [int(x) for x in input().strip().split()]
    s = sum(data)

    data = [(x, i) for i, x in enumerate(data)]

    res = ""

    while s:
        val, i = max(data)
        data[i] = (val-1, i)
        s -= 1
        res += get(i)

        val, i = max(data)
        data[i] = (val-1, i)
        s -= 1

        if max(data)[0] *2 > s:
            data[i] = (val, i)
            s += 1

        else:
            res += get(i)

        res += " "

    return res



T = int(input())
for test_case in range(T):
    print ("Case #{}:".format(test_case+1), work())