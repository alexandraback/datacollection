import sys 


def change(count):
    # int '3, 4,5 '
    count.sort() 
    tmp = 0 
    N = len(count) 

    target = count[N/2]
    for i in count:
        tmp += abs( i - target) 

    #print count , tmp
    return tmp 

def solve(words, N):
    
    word_process = []
    #print words
    for word in words:
        tmp = []
        i=0
        j=1

        word += '*'

        while j < len( word) :
            if word[j] == word[i]:
                pass
            else:
                tmp.append( (word[i], j-i )  ) 
                i=j 
            j+=1
        
        word_process.append(tmp)

    #print word_process
    L = len(word_process[0])
    for i in word_process :
        if L!= len(i) :
            return -1

    total_change= 0
    for i in range(L):
        tmp = word_process[0][i][0]
        count = [ word_process[0][i][1]  ] 
        for j in word_process[1:]:
            if j[i][0] != tmp:
                return -1 
            else:
                count.append(j[i][1])

        total_change += change( count ) 

    return total_change


f = open(sys.argv[1])
cases = int( f.readline().strip()  )

for case in range(1, cases+1):
    
    N = int(f.readline().strip() )
    
    words = []

    for _ in range(N):
        words.append( f.readline().strip()  ) 

    ans = solve(words, N )
    if ans < 0:
        print "Case #%d: Fegla Won" % case
    else:
        print "Case #%d: %d" % ( case, ans ) 
