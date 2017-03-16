from collections import Counter

def analyse(string):

    senators = [int(s) for s in string.split(" ")]

    print("")

    answer = ""
    while max(senators) > 0:
        maxV1 = max(senators)
        maxI1 = senators.index(maxV1)
        rest = senators[:maxI1] + senators[maxI1+1:]
        maxV2 = max(rest)
        maxI2 = rest.index(maxV2)

        if(maxI2 >= maxI1):
            maxI2 += 1

        #print(senators, rest, maxV1, maxV2)

        if maxV1 == maxV2:
            if senators.count(1) % 2 == 1:
                n2 = 0
            else:
                n2 = 1
        else:
            n2 = 0

        answer += intToChar(maxI1)
        if n2 == 1:
            answer += intToChar(maxI2)
        answer += " "

        senators[maxI1] -= 1
        senators[maxI2] -= n2

        total = sum(senators)
        for s in senators:
            if s > total/2:
                print("ERROR", total, s)

    return answer[:-1]

def intToChar(i):
    return chr(65 + i)

def run(name):
    lines = [l.rstrip() for l in open(name + ".in", mode='r')]
    n = int(lines[0])
    
    out = open(name + ".out",mode='w')
    for i in range(n):
        answer = analyse(lines[2+2*i])
        out.write("Case #" + str(i+1) + ": " + answer + "\n")
    out.close()

run("A-small-attempt0")
