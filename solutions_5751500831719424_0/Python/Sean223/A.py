__author__ = 'Sean'

from math import fabs

def getLetterCount(phrase, letter):
    length = len(phrase)
    if length == 0 or phrase[0] != letter:
        return 0
    else:
        rv = 0
        for i in range(length):
            if phrase[i] != letter:
                break
            rv += 1
        return rv

fileIn = open('A-small.in', 'r')
fileLines = fileIn.readlines()
fileIn.close()

it = iter(fileLines)

numbCases = int(next(it))

output = ""

for case in range(numbCases):
    numbStrings = int(next(it))
    strings = []
    for _i in range(numbStrings):
        strings.append(str(next(it).strip()))

    counts = [[] for _j in range(numbStrings)]

    done = False
    possible = True
    while not done:
        letter = strings[0][0]
        for j in range(numbStrings):
            count = getLetterCount(strings[j], letter)
            counts[j].append(count)
            if count < len(strings[j]):
                strings[j] = strings[j][count:]
            else:
                strings[j] = ""

            if count == 0:
                possible = False
                done = True
                break
        if len(strings[0]) == 0:
            for string in strings:
                if len(string) > 0:
                    possible = False
                    break
            done = True

    if possible:
        cost = int(0)
        for i in range(len(counts[0])):
            cheapest = 100000000

            checked = []
            for j in range(numbStrings):
                if counts[j][i] in checked:
                    continue
                digitCost = 0
                for k in range(numbStrings):
                    digitCost += int(fabs(counts[j][i] - counts[k][i]))
                if digitCost < cheapest:
                    cheapest = digitCost
                checked.append(counts[j][i])

            cost += cheapest

        output += "Case #{0}: {1}\n".format(case+1, cost)

    else:
        output += "Case #{0}: {1}\n".format(case+1, "Fegla Won")


with open('small.txt', 'w') as fileOut:
    fileOut.write(output)
