input = open('input', 'r')
output = open('output', 'w')

def compress_word(word):
    l = []
    count = 0
    i = 0
    while i < len(word):
        count +=1
        if i == len(word) -1:
            l.append((word[i],count))
            break
        if word[i] != word[i+1]:
            l.append((word[i],count))
            count = 0
        i += 1
    return l

testcases = int(input.readline().strip())
for testcase in xrange(1, testcases+1):
    print "Testcase %d" % testcase
    word_no = int(input.readline().strip())
    counts = []
    for i in xrange(word_no):
        word = input.readline().strip()
        counts.append(compress_word(word))
    for count in counts:
        print count
    moves = 0
    ret = False
    for i in xrange(max(len(count) for count in counts)):
        letters = []
        repeaters = []
        for count in counts:
            if i >= len(count):
                 output.write("Case #%s: %s\n" % (testcase, "Fegla won"))
                 ret = True
                 break
            l, r = count[i]
            letters.append(l)
            repeaters.append(r)
        if ret:
            break
        if len(set(letters)) != 1:
            output.write("Case #%s: %s\n" % (testcase, "Fegla won"))
            ret = True
            break
        if ret:
            break
        mean = sum(repeaters)/len(repeaters)
        target = None
        d = 1000
        for r in repeaters:
            if abs(r-mean)<d:
                t = r
                d = abs(r-mean)
        print "For letter %s target is %d" % (letters[0], t)
        for r in repeaters:
            moves += abs(r - t)
        print moves
    if ret:
        continue
    output.write("Case #%s: %d\n" % (testcase, moves))


input.close()
output.close()
