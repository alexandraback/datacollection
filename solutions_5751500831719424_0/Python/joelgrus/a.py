infile = "A-small-attempt0.in"
outfile = "A-small.out"

lines = [l.strip() for l in open(infile,"r")]
from collections import defaultdict, Counter
from functools import partial

num_cases = int(lines[0])
lines = lines[1:]

cases = []

for _ in range(num_cases):
    
    N = int(lines[0])
    case = lines[1:(N+1)]
    lines = lines[(N+1):]
    cases.append(case)

def letrify(s):
    last_char = None
    count = 0
    results = []
    for c in s:
        if last_char is None:
            last_char = c
            count = 1
        elif last_char == c:
            count += 1
        else:
            results.append( (last_char, count) )
            last_char = c
            count = 1
    if count > 0:
        results.append( (last_char, count) )

    return results

def unique_repr(let):
    return ''.join(x[0] for x in let)
    
def process_case(case):

    lets = [letrify(s) for s in case]
    
    num_reps = len(set(unique_repr(let) for let in lets))
    
    if num_reps != 1:
        return "Fegla Won"

    count = 0
    
    num_positions = len(lets[0])
    
    for i in range(num_positions):
        counts = sorted([let[i][1] for let in lets])
        least_moves = None
        
        for j, c in enumerate(counts):
            moves = sum(abs(x - c) for k, x in enumerate(counts)
                        if k != j)
            if least_moves is None or moves < least_moves:
                least_moves = moves
                
        count += least_moves
        
    return count        

with open(outfile,"w") as g:
    
    for i, case in enumerate(cases):
        g.write("Case #" + str(i + 1) + ": " + str(process_case(case)) + "\n")
    

