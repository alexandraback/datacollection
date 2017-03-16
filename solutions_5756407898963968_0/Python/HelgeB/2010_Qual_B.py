'''
Created on 15.03.2014

@author: Helge
'''

file = open('A-small-attempt0.in', 'r')
output = open('output', 'w')

numberOfTestcases = file.readline()

for i in range(0, int(numberOfTestcases)):
    firstAnswer = int(file.readline())
    firstGrid = []
    firstGrid.append(file.readline().replace('\n', '').split(' '))
    firstGrid.append(file.readline().replace('\n', '').split(' '))
    firstGrid.append(file.readline().replace('\n', '').split(' '))
    firstGrid.append(file.readline().replace('\n', '').split(' '))
    secondAnswer = int(file.readline())
    secondGrid = []
    secondGrid.append(file.readline().replace('\n', '').split(' '))
    secondGrid.append(file.readline().replace('\n', '').split(' '))
    secondGrid.append(file.readline().replace('\n', '').split(' '))
    secondGrid.append(file.readline().replace('\n', '').split(' '))
    firstRow = firstGrid[firstAnswer-1]
    secondRow = secondGrid[secondAnswer-1]
    
    
    possibleAnswers = set(firstRow).intersection( set(secondRow) )

    l = len(possibleAnswers)
    if l == 0:
        solution = 'Case #' + str(i+1) + ': Volunteer cheated!'
    elif l == 1:
        solution = 'Case #' + str(i+1) + ': ' + possibleAnswers.pop()
    else:
        solution = 'Case #' + str(i+1) + ': Bad magician!'
        
    print(solution)
    output.write(solution + '\n')  
    
    
'''  
counter = 0
for line in file:
    counter = counter + 1
    wordsReversed = line.replace('\n', '').split(' ')
    wordsReversed.reverse()
    solution = 'Case #' + str(counter) + ': ' + ''.join(word + ' ' for word in wordsReversed)
    print(solution)
    output.write(solution + '\n')
'''