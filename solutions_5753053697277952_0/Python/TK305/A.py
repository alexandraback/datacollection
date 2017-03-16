def indexOfMax(lst):
    ind = 0
    max = 0
    for i in range(len(lst)):
        if max < lst[i]:
            ind = i
            max = lst[i]
    return ind

if __name__ == "__main__":
    with open("A-small-attempt0.in", 'r') as inputf:
        outputf=open("A-small.out", 'w')
        line = inputf.readline()
        line = line.rstrip("\n")
        test_num = int(line)

        for i in range(1, test_num + 1):
            line = inputf.readline()
            line = inputf.readline().rstrip('\n')
            temp = line.split(" ")
            senators = [int(n) for n in temp]
            tot = sum(senators)
            evac = []

            while tot > 0:
                step = ''
                if tot % 2 == 0:
                    max1 = indexOfMax(senators)
                    step += chr(max1+65)
                    senators[max1] -= 1
                    max2 = indexOfMax(senators)
                    step += chr(max2+65)
                    senators[max2] -= 1
                    tot -= 2
                else:
                    max1 = indexOfMax(senators)
                    step += chr(max1+65)
                    senators[max1] -= 1
                    tot -=1
                evac.append(step)

            evacplan = " ".join(evac)
            result = "Case #{0}: {1}".format(i, evacplan)
            outputf.write(result)

            if i < test_num:
                outputf.write("\n")