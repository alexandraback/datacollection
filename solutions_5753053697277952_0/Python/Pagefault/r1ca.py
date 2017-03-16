INPUT_FILE = r'D:\Downloads\FromChrome\A-small-attempt0.in'
#INPUT_FILE = r'D:\Downloads\FromChrome\sample.in'
OUTPUT_FILE = INPUT_FILE.replace('.in', '.out')

inputFile = file(INPUT_FILE, 'rb')
numQuestions = int(inputFile.readline())
outputFile = file(OUTPUT_FILE, 'wb')

def solveQuestion(members):
    plan = []
    topParty = max(members)
    while 0 != topParty:
        first = members.index(topParty)
        members[first] -= 1
        secondParty = max(members)
        second = None
        if 0 != secondParty:
            total = sum(members)
            second = members.index(secondParty)
            members[second] -= 1
            if 1 == sum(members):
                members[second] += 1
                second = None
        plan.append((first, second))
        topParty = max(members)
    result = ''
    for first, second in plan:
        result += chr(ord('A') + first)
        if None != second:
            result += chr(ord('A') + second)
        result += ' '
    return result.strip()

for q in xrange(numQuestions):
    outputFile.write("Case #%d: " % (q+1))
    # Don't forget to read length of a list
    numParties = int(inputFile.readline().strip())
    members = [int(x) for x in inputFile.readline().strip().split()]
    if len(members) != numParties:
        raise Exception("Parse error")
    result = solveQuestion(members)
    outputFile.write(result)
    outputFile.write("\n")

outputFile.close()
inputFile.close()
# print file(OUTPUT_FILE, 'rb').read()
