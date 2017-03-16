import collections

n = int(raw_input())

for i in range(n):
    row1 = int(raw_input())
    lines = [raw_input().split() for x in range(4)]
    row2 = int(raw_input())
    lines2 = [raw_input().split() for x in range(4)]
    #print lines[row1 - 1], lines[row2 - 1]
    c = collections.Counter(lines[row1 - 1] + lines2[row2 - 1])

    multiple = list([x for x, y in c.items() if y > 1])
    l = len(multiple)
    if l == 0:
        r = "Volunteer cheated!"
    if l == 1:
        r = multiple[0]
    if l > 1:
        r = "Bad Magician!"
    print("Case #{}: {}".format(i + 1, r))


