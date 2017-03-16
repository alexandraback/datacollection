# Pull one from the most populated party
# If there's a problem, pull one from the new most populated party


def getEvacuationPlan(senateList):
    evacPlan = []
    while sum(senateList) > 0:
        maxIndex = senateList.index(max(senateList))
        evac = [maxIndex]
        senateList[maxIndex] -= 1
        if max(senateList) > sum(senateList)/2.0:
            maxIndex = senateList.index(max(senateList))
            evac += [maxIndex]
            senateList[maxIndex] -= 1
        evacPlan += [evac]
    return evacPlan


def evacPlanToString(evacPlan):
    ret = ''
    for evac in evacPlan:
        for senator in evac:
            ret += chr(senator+65)
        ret += ' '
    return ret
            
inputF = open('A-large.in', 'r')
output = open('A-large.out', 'w')

numCases = int(inputF.readline())

for i in range(numCases):
    numParties = int(inputF.readline())
    senateList = [int(x) for x in inputF.readline().split()]
    
    evacPlan = evacPlanToString(getEvacuationPlan(senateList))

    output.write('Case #' + str(i+1) + ': ')
    output.write(evacPlan + '\n')

inputF.close()
output.close()
