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

def haircut():
    inputs = open('B-small-attempt0.in', 'r')
    output = open('haircut-ans.txt', 'w')
    cases = int(inputs.readline())

    for case in range(0, cases):
        print "Case %d:" % case
        info = inputs.readline().split(' ')
        B = int(info[0])
        N = int(info[1])
        numMinutes = inputs.readline().split(' ')

        observedN = N-B
        if B > N:
            answer = N
        else:
            answer = 0
            summation = 0
            for i in range(0, B):
                numMinutes[i] = int(numMinutes[i])
                summation += 1.0/numMinutes[i]

            estN = int(math.floor(observedN/summation))

            left = [0]*B
            curN = 0
            for i in range(0,B):
                left[i] = numMinutes[i] - (estN % numMinutes[i])
                if left[i] == numMinutes[i]:
                    answer = i+1
                curN += int(math.floor(estN/numMinutes[i]))

            while curN != observedN:
                smallest = 10000000
                smallestIndex = -1
                for i in range(0,B):
                    if left[i] < smallest:
                        smallest = left[i]
                        smallestIndex = i
                left[smallestIndex] += numMinutes[smallestIndex]
                answer = smallestIndex+1
                curN += 1

        result = 'Case #%d: %d\n' % (case+1, answer)
        output.write(result)


haircut()