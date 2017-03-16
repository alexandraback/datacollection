import math

__author__ = "imdreamrunner"
__email__ = "imdreamrunner@gmail.com"


test = int(input())


for t in range(1, test+1):
    print("Case #" + str(t) + ": ", end="")

    n = int(input())
    m = [int(i) for i in input().split(" ")]

    m1 = 0
    m2 = 0
    lgt = 0
    for c in range(n-1):
        a = m[c]
        b = m[c+1]
        if b < a:
            m1 += a - b
            if a - b > lgt:
                lgt = a - b

    spd = lgt / 10
    spd10 = spd * 10

    for c in range(n-1):
        a = m[c]
        if a > spd10:
            m2 += spd10
        else:
            m2 += a

    print(m1, int(m2))