### Set the input and output file names
import time
import datetime
import string
import operator

filename = 'A-small-attempt0'
input_filename = filename + '.in'
output_filename = filename + '.out.' + datetime.datetime.fromtimestamp(time.time()).strftime('%Y%m%d-%H%M%S') + '.txt'

def findmax(arr_int):
    m = max(arr_int)
    return [i for i, j in enumerate(arr_int) if j == m]



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
        caseSize_r = 1                          # number of rows in each case; default = 1
        caseSize_c = 1                          # number of columns in each case; default = 1
        
        infoLines = True                        # Toggle according to question
        #infoLines = False                       # Toggle according to question
        
        ### i.e. infoLines == True
        if infoLines:
            while lineNum < len(lines):
                ### A new case! Initialize some variables
                caseNum += 1                                    # case number count
                party_count = int(lines[lineNum].split(' ')[0])  
                party_sizes = map(int, lines[lineNum + 1].split(' '))
                party_names = string.uppercase[:party_count]
                room_total = sum(party_sizes)
                
                print('--------')
                print('Case #%d: %s' % (caseNum, " ".join(str(x) for x in party_names)))
                print('Case #%d: %s' % (caseNum, " ".join(str(x) for x in party_sizes)))
                print('Case #%d: %d total people' % (caseNum, room_total))
                print('Case #%d: maxcases in index: %s' % (caseNum, " ".join(str(x) for x in findmax(party_sizes))))
                print('Case #%d: %d maxcases' % (caseNum, len(findmax(party_sizes))))
                
                ### Do the Work!
                ### TODO!
                myAns = ''
                while room_total > 0:
                    #if room_total == 1:
                    #    myAns = join(myAns, ' ', 
                    if room_total >= 4:
                        party_maxes = findmax(party_sizes)
                        if len(party_maxes) == 1:
                            print('step. 4+ remain (1 max)')
                            party_sizes[party_maxes[0]] += -1
                            myAns = myAns + (' %s' % (party_names[party_maxes[0]]))
                            print('%s' % (party_names[party_maxes[0]]))
                            print('%s' % (" ".join(str(x) for x in party_sizes)))
                            room_total += -1
                        else: 
                            print('step. 4+ remain (2+ max)')
                            party_sizes[party_maxes[0]] += -1
                            party_sizes[party_maxes[1]] += -1
                            myAns = myAns + (' %s%s' % (party_names[party_maxes[0]],party_names[party_maxes[1]]))
                            print('%s%s' % (party_names[party_maxes[0]],party_names[party_maxes[1]]))
                            print('%s' % (" ".join(str(x) for x in party_sizes)))
                            room_total += -2
                    elif room_total == 3:
                        print('step. 3 remain')
                        party_maxes = findmax(party_sizes)
                        party_sizes[party_maxes[0]] += -1
                        myAns = myAns + (' %s' % (party_names[party_maxes[0]]))
                        print('%s' % (party_names[party_maxes[0]]))
                        print('%s' % (" ".join(str(x) for x in party_sizes)))
                        room_total += -1
                    elif room_total == 2:
                        print('step. 2 remain')
                        party_maxes = findmax(party_sizes)
                        party_sizes[party_maxes[0]] += -1
                        party_sizes[party_maxes[1]] += -1
                        myAns = myAns + (' %s%s' % (party_names[party_maxes[0]],party_names[party_maxes[1]]))
                        print('%s%s' % (party_names[party_maxes[0]],party_names[party_maxes[1]]))
                        print('%s' % (" ".join(str(x) for x in party_sizes)))
                        room_total += -2
                    else:
                        print('###################ERROR')
                        room_total = -1

                
                ### Output myArr
                print('Case #%d:%s' % (caseNum, myAns))
                output.write('Case #%d:%s\n' % (caseNum, myAns))

                ### Step
                lineNum += 2
                
        ### i.e. infoLines == False
        else:   
             print('deadend')
                

### END
