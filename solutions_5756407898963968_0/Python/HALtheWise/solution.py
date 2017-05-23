#file('C-large-practice.in').read()
#
dataTable = {'a': '2', 'c': '222', 'b': '22', 'e': '33', 'd': '3', 'g': '4',
             'f': '333', 'i': '444', 'h': '44', 'k': '55', 'j': '5', 'm': '6',
             'l': '555', 'o': '666', 'n': '66', 'q': '77', 'p': '7',
             's': '7777', 'r': '777', 'u': '88', 't': '8', 'w': '9',
             'v': '888', 'y': '999', 'x': '99', 'z': '9999', ' ':'0'}

def processAllInput(text, toFile = False):
    fileName = text
    if toFile:
        text = file(fileName).read()
    finalResult = []
    numTests = int(text.split('\n')[0])
    lines = text.split('\n')
    for i in range(numTests):
        #Problem-specific code starts here############
        
        case = lines[10*i+1:10*i+11]
        firstanswer = int(case[0])
        secondanswer = int(case[5])
        firstline = case[firstanswer].split()
        secondline = case[5+secondanswer].split()
        solution = ''
        overlap = [a for a in firstline if a in secondline]
        if len(overlap) is 0:
            solution = 'Volunteer cheated!'
        elif len(overlap) > 1:
            solution = 'Bad magician!'
        else:
            solution = overlap[0]
        line = 'Case #{0}: {1}'.format(i+1, solution)
        
        #Problem-specific code ends here##############
        if not toFile:
            print line
        finalResult.append(line)
    if toFile:
        file(fileName.split('.')[0]+'.out', 'w').write('\n'.join(finalResult))
