
# -*- coding: utf8 -*-

import sys

# inputFile = "A-sample.in"
inputFile = "A-small-attempt0.in"
# inputFile = "A-large.in"
f = open(inputFile)
sys.stdout = open(inputFile.replace(".in", ".txt"), 'w')
tc_num = int(f.readline().rstrip())

for tc in range(tc_num):
    n = int(f.readline().rstrip())

    l = f.readline().split()
    numbers = []
    for i in l:
        numbers.append(int(i))

    ans = ""
    maxVal = max(numbers)
    while maxVal > 1:
        ind1 = numbers.index(maxVal)
        ansC = chr(ord('A') + ind1)
        numbers[ind1] -= 1
        maxVal = max(numbers)
        if maxVal > 1:
            ind2 = numbers.index(maxVal)
            numbers[ind2] -= 1
            ansC += chr(ord('A') + ind2)
            maxVal = max(numbers)

        ans += " " + ansC

    for i in range(n-2):
        ans += " " + chr(ord('A') + i)

    ans += " " + chr(ord('A') + n-2) + chr(ord('A') + n-1)

    print("Case #" + str(tc + 1) + ":" + ans)

