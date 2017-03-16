def a(strings):
    def runLength(strings):
        run_strings = []
        strings_cnts = []
        run_chars   = []
        for string in strings:
            i = 0
            s = ""
            cnts = []
            chars = ""
            while i < len(string):
                s += string[i]
                chars += string[i]
                count = 1
                j = i + 1
                while j < len(string):
                    if  string[j] == string[i]:      
                        count += 1
                        j += 1
                    else:
                        break
                cnts.append(count)
                s += str(count)
                i = j            
            run_strings.append(s)
            strings_cnts.append(cnts)
            run_chars.append(chars)
        return run_strings, strings_cnts, run_chars
    
    run_strings, strings_cnts, run_chars = runLength(strings)

        

    #checking if possible
 
    for s1 in run_chars:
        for s2 in run_chars:
            if s1 != s2:
                return "Fegla Won"   
        

    #find Minimum
    mini = 0
    refLength = len(strings_cnts[0])
    i = 0
    while i < refLength:
        row = []
        for cnts in range(len(strings_cnts)):
            row.append([strings_cnts[cnts][i], cnts])
        median = sorted(row, key=lambda x: x[0])[len(row)//2]
        for cnts in range(len(strings_cnts)):
            if cnts == median[1]:
                pass
            if strings_cnts[cnts][i] > median[0]:
                mini += strings_cnts[cnts][i] - median[0]
            else:
                mini +=  median[0] - strings_cnts[cnts][i]
        i += 1

    return mini
        
        
        


FILENAME = "A-large"
f = open(FILENAME + '.in', 'r')
T = int(f.readline())
output = []

for i in range(T):
    temp = f.readline().split(' ')
    N = int(temp[0])
    strings = []
    for j in range(N):
        tmp = f.readline()
        if tmp[-1] == '\n':
            tmp = tmp[:-1]
        strings.append(tmp)
        

    output.append("Case #"+str(i+1)+": " + str(a(strings)))
    #print output[i]


f.close()
output = '\n'.join(e for e in output)
f = open(FILENAME + '.out', 'w')
f.write(output)
f.close()
