import re


def cijfertoLetter(cijfer):
    return chr(cijfer + ord('a'))


# returns the position of the maximum of an array
def maxarray(array):
    maxindex = array.index(max(array))
    return maxindex

# returns the sum of an array
def sumarray(array):
    x = 0
    for i in range(len(array)):
        x += array[i]
    return x
i = int(input())
for case in range(i):
    print()
    input()
    senatoren = str(input()).split()
    for i in range(len(senatoren)):
        senatoren[i] = int(senatoren[i])
    reti = ""

    if (sumarray(senatoren) % 2):
        maxindex = maxarray(senatoren)
        reti += (cijfertoLetter(maxindex)) + " "
        senatoren[maxindex] -= 1

    while sumarray(senatoren) > 0:
        maxindex = maxarray(senatoren)
        reti += (cijfertoLetter(maxindex))
        senatoren[maxindex] -= 1
        maxindex = maxarray(senatoren)
        reti += (cijfertoLetter(maxindex)) + " "
        senatoren[maxindex] -= 1

    print("Case #{}: {}".format(case + 1, reti[:-1]))


# 4
# 2
# 2 2
# 3
# 3 2 2
# 3
# 1 1 2
# 3
# 2 3 1
