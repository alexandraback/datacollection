def getMedian(arr):
    arr = arr[:]
    arr.sort()
    if(len(arr) % 2 != 0):
        return arr[(len(arr) - 1) / 2]
    else:
        return arr[len(arr) / 2]

def getCol(arr, j):
    col = []
    for i in xrange(len(arr)):
        col.append(arr[i][j])
    return col
        
def getQuantities(strings):
    quantities = []
    for i in xrange(len(strings)):
        quantities.append([])
        c = '@'
        for j in xrange(len(strings[i])):
            if(c == strings[i][j]):
                quantities[-1][-1] += 1
            else:
                quantities[-1].append(1)
                c = strings[i][j]
    return quantities

def possible(strings):
    pattern = ''
    c = '@'
    for i in xrange(len(strings[0])):
        if(c != strings[0][i]):
            c = strings[0][i]
            pattern = pattern + c
    
    for i in xrange(1, len(strings)):
        tmp_pattern = ''
        c = '@'
        for j in xrange(len(strings[i])):
            if(c != strings[i][j]):
                c = strings[i][j]
                tmp_pattern = tmp_pattern + c
        if(tmp_pattern != pattern):
            return False
    return True

def main():
    input = open('input.txt', 'r')
    output = open('output.txt', 'w')

    T = int(input.readline()) #number of test cases
    
    for casenum in xrange(1, T+1):
        N = int(input.readline())
        strings = []
        for i in xrange(N):
            strings.append(input.readline().strip())
        if(not possible(strings)):
            ans = 'Fegla Won'
        else:
            ans = 0
            quantities = getQuantities(strings)
            for j in xrange(len(quantities[0])):
                med = getMedian(getCol(quantities, j))
                for i in xrange(len(quantities)):
                    ans += abs(quantities[i][j] - med)
            
        outstr = 'Case #' + str(casenum) + ': '
        outstr += str(ans)
        outstr += '\n'
        output.write(outstr)

    input.close()
    output.close()
    
main()