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
    inputs = open('B-large.in', 'r')
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
            if estN > 10 ** 50:
                print "Boom!"

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
                if left[smallestIndex] > 10**50:
                    print "Boom!"
                answer = smallestIndex+1
                curN += 1

        result = 'Case #%d: %d\n' % (case+1, answer)
        output.write(result)

def concave():
    inputs = open('C-small-attempt1.in', 'r')
    output = open('concave-ans.txt', 'w')
    cases = int(inputs.readline())

    for case in range(0, cases):
        print "Case %d:" % case
        result = 'Case #%d:\n' % (case+1)
        output.write(result)
        numTrees = int(inputs.readline())
        trees = []
        for i in range(0, numTrees):
            trees.append(inputs.readline().split(' '))
            trees[i][0] = int(trees[i][0])
            trees[i][1] = int(trees[i][1])

        answers = [3001]*numTrees

        for i in range(0, numTrees):
            for j in range(0, numTrees):
                less = 0
                more = 0
                if i == j:
                    continue
                if (trees[i][0]-trees[j][0]) == 0:
                    for k in range(0, numTrees):
                        if trees[k][0]-trees[i][0] > 0:
                            less += 1
                        elif trees[k][0]-trees[i][0] < 0:
                            more += 1                   
                else:
                    slope = float((trees[i][1]-trees[j][1]))/(trees[i][0]-trees[j][0])
                    intercept = trees[i][1]-slope*trees[i][0]
                    # print "Slope %d" % slope
                    # print "Intercept %d" % intercept
                    for k in range(0, numTrees):
                        # print "Calculated %d" % (trees[k][1]-slope*trees[k][0])
                        if trees[k][1]-slope*trees[k][0] > intercept:
                            less += 1
                        elif trees[k][1]-slope*trees[k][0] < intercept:
                            more += 1
                smaller = min(less, more)
                answers[i] = min(answers[i], smaller)
            if answers[i] == 3001:
                answers[i] = 0
            temp_result = "%d\n" % answers[i] 
            output.write(temp_result)
        print answers


concave()