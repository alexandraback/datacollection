### Set the input and output file names
import time
import datetime
filename = 'A-small-attempt0'
input_filename = filename + '.in'
output_filename = filename + '.out.' + datetime.datetime.fromtimestamp(time.time()).strftime('%Y%m%d-%H%M%S') + '.txt'

### Import other libraries
#import pickle

### Open input file for reading
with open(input_filename) as f:
    lines = f.read().splitlines()

    ### Open output file for writing
    with open(output_filename, 'w') as output:

        ######################################################
        ### Initialise variables from first line of the file
        ######################################################   
        vars = lines[0].split(' ')
        cases = int(vars[0])                    # number of cases
        print(str(cases) + ' cases detected.')  # [soft validation]
        lineNum = 1                             # first case starts here
        caseNum = 0                             # for counting the num of cases
        caseSize_r = 4                          # number of rows in each case; default = 1
        caseSize_c = 4                          # number of columns in each case; default = 1
        
        infoLines = True                        # Toggle according to question
        #infoLines = False                       # Toggle according to question
        
        ### i.e. infoLines == True
        if infoLines:
            while lineNum < len(lines):
                ### A new case! Initialize some variables
                caseNum += 1                                    # case number count
                
                ### PART 1
                guess1 = int(lines[lineNum].split(' ')[0])
                
                ### Case data saved into myArr
                myArr = [[] for x in range(caseSize_r)]
                for r in range(0, caseSize_r):
                    for c in range(0, caseSize_c):
                        myArr[r] = lines[lineNum + r + 1].split(' ')

                ### Do the Work! PART 1
                potentials1 = myArr[guess1-1]
                
                ### Step
                lineNum += caseSize_r + 1
                
                ### PART 2
                guess2 = int(lines[lineNum].split(' ')[0])
                
                ### Case data saved into myArr
                myArr = [[] for x in range(caseSize_r)]
                for r in range(0, caseSize_r):
                    for c in range(0, caseSize_c):
                        myArr[r] = lines[lineNum + r + 1].split(' ')

                ### Do the Work! PART 2
                potentials2 = myArr[guess2-1]
                results = set(potentials1) & set(potentials2)
                if len(results) == 0:
                    msg = 'Volunteer cheated!'
                elif len(results) == 1:
                    msg = ''.join(list(results))
                elif len(results) > 1:
                    msg = 'Bad magician!'
                
                
                ### Output myArr
                print('Case #%d: %s' % (caseNum, msg))
                #print(potentials1)
                #print(potentials2)
                #print(set(potentials1) & set(potentials2))
                output.write('Case #%d: %s\n' % (caseNum, msg))

                ### Step
                lineNum += caseSize_r + 1
                
                
                
        ### i.e. infoLines == False
        else:   
            for caseNum in range(1, cases+1):
                
                ### Do the Work!
                ### TODO! 
                myAns = len(lines[lineNum])
                lineNum += 1
                
                ### Output myAns
                print('Case #%d: %d\n' % (caseNum, myAns))
                output.write('Case #%d: %d\n' % (caseNum, myAns))

                

### END
