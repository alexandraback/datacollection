f = open("a3.in", 'r')
f_out = open("out_A", 'w')

cases = f.readline()

for case in range(int(cases)):
    choose_line1 = int(f.readline())
    for lines in range(1, 5):
        if lines == choose_line1:
            line1 = f.readline()
            continue
        else:
            f.readline()
    choose_line2 = int(f.readline())
    for lines in range(1, 5):
        if lines == choose_line2:
            line2 = f.readline()
            continue
        else:
            f.readline()
    print line1, line2
    result = set(line1.split()) & set(line2.split())
    verdict = ''
    if len(result) == 0:
        verdict = "Volunteer cheated!"
    elif len(result) > 1:
        verdict = "Bad magician!"
    else:
        verdict = str(result.pop())
    print "Case #" + str(case + 1) + ": " + verdict
    f_out.write("Case #" + str(case + 1) + ": " + verdict + '\n')