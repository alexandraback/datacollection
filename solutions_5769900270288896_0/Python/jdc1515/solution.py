with open("B-small-attempt3.in") as f:
    lines = f.readlines()

outputname = 'outputBsmall3.txt'
f = open(outputname, 'w')

cases = int(lines[0])
linenum = 1

def phap(R, C, N):
    num0 = R*C / 2
    num2 = 2
    if R % 2 != 0 and C % 2 != 0:
        num0 += 1
        num2 = 0

    num3 = 0
    if R > 1 and C > 1:
        num3 += (R-1) / 2
        num3 += (C-1) / 2
        num3 *= 2
    else:
        if R == 1:
            num2 = C / 2
        if C == 1:
            num2 = R / 2

    unhap = 0
    cur = N
    while cur > 0:
        cur -= num0
        if cur <= 0:
            break
        cur -= num2
        if cur <= 0:
            unhap += 2 * (cur + num2)
            break
        unhap += 2 * num2

        cur -= num3
        if cur <= 0:
            unhap += 3 * (cur + num3)
            break
        unhap += 3 * num3

        unhap += 4 * cur
        break
    return unhap

def neg3comp(R, C):
    neg3 = (R-3) / 2
    neg3 *= 2
    if C % 2 == 0:
        neg3 += 1
    return neg3

def nhap(R, C, N):
    total = phap(R,C,R*C)
    if R == 1 or C == 1:
        return total
    neg4 = ((R-2) * (C-2)) / 2
    if R % 2 != 0 and C % 2 != 0:
        neg4 += 1
    neg3 = neg3comp(R, C) + neg3comp(C, R)

    cur = total - N
    while cur > 0:
        cur -= neg4
        if cur <= 0:
            total -= 4 * (neg4 + cur)
            break
        total -= 4 * neg4
        cur -= neg3
        if cur <= 0:
            total -= 3 * (neg3 + cur)
        total -= 3 * neg3

        break

    return total

for i in range(cases):
    nums = lines[linenum].split(" ")
    nums = [int(j) for j in nums]
    R, C, N = nums
    linenum += 1

    unhap = min(phap(R, C, N), nhap(R,C,N))

    f.write("Case #" + str(i+1) + ": " + str(unhap) + "\n")


f.close()

with open(outputname, 'r') as f:
    print(f.read())
