
'''
Created on Apr 12, 2013

@author: herman
'''


infile = open("input.txt","r")
outfile = open("output.txt","w")

trials = int(infile.readline())

def convert(word):
    min_word = ''
    letter_counts = []
    lchar = word[0]
    count = 1
    windex = 1
    while windex < len(word):
        nchar = word[windex]
        if nchar == lchar:
            count += 1
        else:
            # change to next character
            min_word += lchar
            letter_counts.append(count)
            lchar = nchar
            count = 1
        windex += 1
    # save last character
    min_word += lchar
    letter_counts.append(count)
    return min_word,letter_counts
    
def get_min(counts):
    mincount = min(counts)
    maxcount = max(counts)
    tots = []
    for i in xrange(mincount,maxcount+1):
        tots.append(sum([abs(c - i) for c in counts]))
    return min(tots)

def moves_needed(words):
    min_words = []
    letter_counts = []
    for w in words:
        mw,lc = convert(w)
        min_words.append(mw)
        letter_counts.append(lc)
    all_same = (len(set(min_words)) == 1)
    if not all_same:
        return None
    
    # calculate min
    moves = 0
    clength = len(letter_counts[0])
    for i in xrange(clength):
        comps = [lc[i] for lc in letter_counts]
        moves += get_min(comps)

    return moves

for i in xrange(trials):
    N = int(infile.readline())
    words = []
    for j in xrange(N):
        words.append(infile.readline().strip())
    
    result = moves_needed(words)
    if result == None:
        s = "Case #%d: %s\n" % (i+1,'Fegla Won')
    else:
        s = "Case #%d: %d\n" % (i+1,result)        
    outfile.write(s)
    print s
    
infile.close()
outfile.close()
