__author__ = 'Glen'
import re
import sys
numCases = int(input().strip())
for caseNum in range(numCases):
    numStrings = int(input().strip())
    strings = []
    shortest = None
    averageLen = 0
    for i in range(numStrings):
        newStr = input().strip()
        strings.append(newStr)
        averageLen += len(newStr)
        if shortest is None or len(newStr) < len(shortest):
            shortest = newStr

    averageLen /= len(strings)

    regexStr = ''
    lastChar = None
    for char in shortest:
        if char != lastChar:
            regexStr += char + '+'
            lastChar = char

    pattern = re.compile(regexStr)
    non_matching = False
    for string in strings:
        res = pattern.match(string)
        if res and res.span() == (0, len(string)):
            #print(string + ' matched')
            pass
        else:
            non_matching = True
            break

    if non_matching:
        result = 'Fegla Won'
    else:
        result = 0
        #first = True
        regexStr = regexStr.replace('+', '')
        while True:
            char = regexStr[-1]
            #print('matching against ' + char)
            same = 0
            diff = 0
            for i in range(len(strings)):
                if len(strings[i]) > 0:
                    chari = strings[i][-1]
                    if chari == char:
                        strings[i] = strings[i][:-1]
                        same += 1
                    else:
                        diff += 1
                else:
                    diff += 1
            #if same > diff:
            #    result += diff
            #    #first = False
            #else:
            #    #if first:
            #    result +=
            result += min(same, diff)
            #print('same: ' + str(same) + ' diff: ' + str(diff) + ' result: ' + str(result))
            if same == 0:
                regexStr = regexStr[:-1]
            if len(regexStr) == 0:
                test = sum(map(len, strings))
                if test != 0:
                    sys.stderr.write('test was ' + test)
                break





    print('Case #{}: {}'.format(caseNum + 1, result))