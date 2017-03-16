from numpy import median, abs
import fileinput

def nextChar(word, index):
    ini_index = index
    for ind in range(index+1,len(word)):
        if word[ind] != word[ind-1]:
            return word[ind-1],ind-ini_index,ind
    return word[-1], len(word)-ini_index, len(word)

def resumeWord(word):
    vals = []
    quants = []
    val, quant, ind = nextChar(word,0)
    vals.append(val)
    quants.append(quant)
    while ind != len(word):
        val, quant,ind = nextChar(word,ind)
        vals.append(val)
        quants.append(quant)        
    return vals,quants

def check(words):
    wr = [resumeWord(word) for word in words] 
    for i in range(len(wr)-1):
        if wr[i][0] != wr[i+1][0]:
            return False
    return [x[1] for x in wr]

def computeMinimum(wws):
    ref = median(wws)
    return sum([abs(ref-x) for x in wws])

def doIt(words):
    cw = check(words)
    if cw:
        return str(int(sum([computeMinimum([cw[j][i] for j in range(len(cw))])  for i in range(len(cw[0]))])))
    else:
        return "Fegla Won"
    
fil = fileinput.input()
cases = int(next(fil))
for case in range(cases):
    words = int(next(fil))
    w = [next(fil).replace("\n","") for word in range(words)]
    print "Case #"+str(case+1)+": "+doIt(w)
    
    
    
    
    
    
    
    