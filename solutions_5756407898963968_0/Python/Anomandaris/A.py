from IOManager import formatInput, readInput, writeOutput

def solve(data):
    cases = formatInput(data,[1,4,1,4],[int,str,int,str])
    results = []
    
    for firstA, firstS, secondA, secondS in cases:
        
        firstP = firstS[firstA-1].split(" ")
        secondP = secondS[secondA-1].split(" ")
        
        intersection = [s for s in firstP if s in secondP]
        size = len(intersection)
        
        results.append("Bad magician!" if size > 1 else (intersection[0] if size == 1 else "Volunteer cheated!"))
    
    return results;
    
    
question = "A"
roundNumber = "1"
name = "small-attempt0"

inputName = question + "-" + name + ".in"
outputName = question + "-" + name + ".out"

testCases, data = readInput(inputName)
writeOutput(solve(data),outputName)


    