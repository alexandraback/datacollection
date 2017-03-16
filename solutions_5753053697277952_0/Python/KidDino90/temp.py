import re

inputFile = open ('input.in', 'r')


def main ():
    listL = inputFile.read ().splitlines ()
    stage1 (listL)

##############################################################################################################################
##############################################################################################################################
##############################################################################################################################
##############################################################################################################################
##############################################################################################################################





    
def stage1 (listL):
    ###############################################################
    ############                                   ################
    ############        Global Variables           ################
    ############                                   ################
    ###############################################################
    output = []
    global CasePointer
    CasePointer = 1 #Change this if second line isn't 1st case
    ###############################################################
    for i in range (1, int(listL[0]) + 1):
        answer = ""
        alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        
        ###############################################################
        ###############################################################
        ###############             START            ##################
        ###############################################################
        ###############################################################
        nParties = int(listL[CasePointer])
        lSenators = ((listL[CasePointer+1])).split()
        lSenators = list(map(int, lSenators))
        
        while completed(lSenators) == False:
            answer = answer + " "
            
            biggest = 0
            index = -1
            for j in range(0, len(lSenators)):
                if (lSenators[j]) > biggest:
                    biggest = (lSenators[j])
                    index = j
            if index != -1:
                lSenators[index] = lSenators[index]-1
                answer = answer + alp[index]
            if total(lSenators) == 2:
                continue
            biggest = 0
            index = -1
            for j in range(0, len(lSenators)):
                if (lSenators[j]) > biggest:
                    biggest = (lSenators[j])
                    index = j
            if index != -1:
                lSenators[index] = lSenators[index]-1
                answer = answer + alp[index]
            
      
        
        ###############################################################
        ###############################################################
        ###############################################################
        ###############################################################
        ###############################################################
    
        outputLine = "Case #" + str(i) + ": " + answer
        print (outputLine)
        output.append (outputLine)
        printOutput (output)
        CasePointer = CasePointer + 2



def completed(lSenators):
    for j in lSenators:
        if j != 0:
            return False
    return True

def total(lSenators):
    total = 0
    for j in lSenators:
        total = total + j
    return total


###############################################################                   
###############################################################
###############################################################
###############################################################
###############################################################
        
def printOutput (output):
    outputFile = open('output', 'w')
    for i in range (0, len (output) - 1):
        outputFile.write (output[i] + "\n")
    outputFile.write (output[len (output) - 1])
            


main()
