import scipy

def runCases(fname,outname):
    case = 0
    cases = 0
    fakes = 0
    linesLeft = 0
    with open(fname,'rU') as f:
        for line in f:
            if cases == 0: 
                cases = int(line)
                continue
            if case > cases: break
            if linesLeft == 0:
                numParties = int(line)
                linesLeft = 1
                case += 1
                continue
            #now check for uniques.
            perPartySplit = scipy.array([int(x) for x in line.split(" ")])
            #print word
            ans = getEvacs(perPartySplit,numParties)
            linesLeft -= 1
            if linesLeft == 0:
                outputCase(ans,outname,case)
        
def outputCase(ans,outname,case):
    if case == 0: pass
    if case == 1: f = open(outname,'w')
    else: f = open(outname,'a')
    f.write("Case #"+str(case)+": "+str(ans)+"\n")
    
def getEvacs(perPartySplit,numParties):
    evacs = ""
    while scipy.sum(perPartySplit) > 0:
        perPartySplit, evacs = addEvac(perPartySplit, evacs)
    return evacs
    
def addEvac(perPartySplit, evacs):
    parties = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]
    if scipy.sum(perPartySplit) % 2 == 1:
        evacs += parties[scipy.argmax(perPartySplit)]
        perPartySplit[scipy.argmax(perPartySplit)] -= 1
    else:
        evacs += parties[scipy.argmax(perPartySplit)]
        perPartySplit[scipy.argmax(perPartySplit)] -= 1
        evacs += parties[scipy.argmax(perPartySplit)]
        perPartySplit[scipy.argmax(perPartySplit)] -= 1
    evacs += " "
    return perPartySplit, evacs

#-attempt0
runCases("A-small-attempt0.in","A-small.out")