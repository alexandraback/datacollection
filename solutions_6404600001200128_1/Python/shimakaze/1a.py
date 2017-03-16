import math

def mushrooms():
    inputs = open('A-large.in', 'r')
    output = open('mushroom-ans.txt', 'w')
    cases = int(inputs.readline())

    for case in range(0, cases):
        length = int(inputs.readline())
        numMushroom = inputs.readline().split(' ')

        total = 0
        maximum = 0
        total2 = 0

        for i in range(0, len(numMushroom)):
            numMushroom[i] = int(numMushroom[i])
            if i > 0 and numMushroom[i] < numMushroom[i-1]:
                total += numMushroom[i-1]-numMushroom[i]
                if (numMushroom[i-1]-numMushroom[i]) > maximum:
                    maximum = numMushroom[i-1]-numMushroom[i]

        for i in range(0, len(numMushroom)-1):
            if numMushroom[i] < maximum:
                total2 += numMushroom[i]
            else:
                total2 += maximum


        result = 'Case #%d: %d %d\n' % (case+1, total, total2)
        output.write(result)

mushrooms()