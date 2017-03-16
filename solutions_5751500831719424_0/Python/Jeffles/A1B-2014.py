import sys
import string
trans = string.maketrans('abcdefghijklmnopqrstuvwxyz', 'yhesocvxduiglbkrztnwjpfmaq')

fname = 'A'

output_format = 'single'
scale_op = input('Data Scale? 0 - sample,  1 - small,  2 - large: ')
scale = ''
if scale_op == 0: scale = 'small-practice'
elif scale_op == 1: scale = 'small'
elif scale_op == 2: scale = 'large'
else: sys.exit(0)

input_file = open(fname + '-' + scale + '.in', 'r')
output_file = open(fname + '-' + scale + '.out', 'w')


def check(line):
    #sys.stdout.write("Checking "+line+"\n")
    if "." in line: return 0
    if "X" in line and "O" in line: return 0
    if "X" in line: return "X won"
    return "O won"

def score_change(scores, cur_score):
    min = scores[0]
    max = scores[0]
    maxs = 0
    mins = 0
    print scores
    for x in scores:
        if x < min:
            min = x
            mins = 1
        elif x > max:
            max = x
            maxs = 1
        else:
            if x == max:
                maxs += 1
            if x == min:
                mins += 1
    if mins < maxs:
        for x in range(len(scores)):
            if scores[x] == min:
                scores[x] += 1
                cur_score +=1
    elif maxs < mins:
        for x in range(len(scores)):
            if scores[x] == max:
                scores[x] -= 1
                cur_score +=1
    elif min != max:
        for x in range(len(scores)):
            if scores[x] == max:
                scores[x] -= 1
                cur_score +=1
    elif mins == maxs:
        return cur_score

    print "Recursion ", scores, cur_score, mins, min, maxs, max
    return score_change(scores, cur_score)


def process(fp):
    lines = int(fp.readline().rstrip())
    cases = []
    changes = 0
    letters = []
    for word in range(lines):
        cases.append(fp.readline().rstrip())

    letter = cases[0][0]
    while letter:
        letters = []
        print "letter is", letter
        for word in range(lines):
            i = 0
            if len(cases[word]) == 0:
               return "Fegla Won"
            print "77", cases[word], word, letter
            while cases[word][0] == letter:
                cases[word]=cases[word][1:]
                i = i+1
                if len(cases[word]) == 0:
                    break
            if i == 0:
                return "Fegla Won"

            letters.append(i)
        changes += score_change(letters,0)
        print "Now score is ", changes

        if len(cases[0]) == 0:
            for word in range(lines):
                if len(cases[word]) > 0:
                    return "Fegla Won"
            return changes
        letter = cases[0][0]



    # answer = "Game has not completed" #ongoing
    # l = fp.readline().rstrip()+fp.readline().rstrip()+fp.readline().rstrip()+fp.readline().rstrip()
    # fp.readline().rstrip()
    # if not "." in l: answer = "Draw" #draw
    # ans = check(l[0:4])
    # if ans:
    #     return (ans)
    # ans = check(l[4:8])
    #
    # if ans:
    #     return (ans)
    # ans = check(l[8:12])
    # if a
    #     return (ans)
    # ans = check(l[12:16])
    # if ans:
    #     return (ans)
    #
    # start = 0
    # ans = check(l[start]+l[start+4]+l[start+8]+l[start+12])
    # if ans:
    #     return (ans)
    # start = 1
    # ans = check(l[start]+l[start+4]+l[start+8]+l[start+12])
    # if ans:
    #     return (ans)
    # start = 2
    # ans = check(l[start]+l[start+4]+l[start+8]+l[start+12])
    # if ans:
    #     return (ans)
    # start = 3
    # ans = check(l[start]+l[start+4]+l[start+8]+l[start+12])
    # if ans:
    #     return (ans)
    # ans = check(l[0]+l[5]+l[10]+l[15])
    # if ans:
    #     return (ans)
    # ans = check(l[4]+l[7]+l[10]+l[13])
    # if ans:
    #     return (ans)
    #
    #
    # return (answer)
    

def format_output(fp, i, result):
    if output_format == 'single':
        fp.write('Case #%d: %s\n' % (i, result))
    elif output_format == 'multiple':
        fp.write('Case #%d:\n' % (i,))
        for r in result:
            fp.write('%s\n' % r)
    else:
        print 'No output format.'
    print('Case #%d: %s' % (i, result))

T = int(input_file.readline().rstrip('\n'))
for i in range(1, T+1):
    result = process(input_file)
    format_output(output_file, i, result)

input_file.close()
output_file.close()

print('Done.')
