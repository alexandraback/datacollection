import sys

err = 'Fegla Won'
def process(word):
    count = []
    for i in range(len(word)):
        if i > 0 and word[i] == word[i-1]:
            c, r = count[-1]
            count[-1] = (c, r+1)
        else:
            count.append((word[i], 1))
    return count

def closest(reps):
    m = 1e6
    for i in range(reps[0], reps[-1]+1):
        mm = sum( abs(j-i) for j in reps)
        m = min(m, mm)
    return m
        
def resolve(words):
    signatures = map(process, words)
    L = len(signatures[0])
    for s in signatures:
        if len(s) != L:
            return err
    p_words = zip(*signatures)
    r = 0
    for occ in p_words:
        c0, _ = occ[0]
        reps = []
        for c, rep in occ:
            if c != c0:
                return err
            reps.append(rep)
        reps.sort()
        r += closest(reps)
    return r
        

input_file = sys.stdin
output_file = open('output', 'w')

T = int(input_file.readline())

for i in range(1, T + 1):
    
    N = int(input_file.readline())
    words = [ input_file.readline().strip() for _ in range(N)]
    sol = 'Case #%d: %s\n' % (i, resolve(words))
    
    print sol
    output_file.write(sol)


    

