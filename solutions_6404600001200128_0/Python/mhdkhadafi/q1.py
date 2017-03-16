__author__ = 'muhammadkhadafi'

def case_one(mushrooms):
    total = 0
    for i in range(0, len(mushrooms)-1):
        if mushrooms[i] > mushrooms[i+1]:
            total += (mushrooms[i] - mushrooms[i+1])
    return total

def case_two(mushrooms):
    total = 0
    rate = -1
    for j in range(0, len(mushrooms)-1):
        if rate < (mushrooms[j] - mushrooms[j+1]):
            rate = mushrooms[j] - mushrooms[j+1]
    if rate == -1:
        return 0
    # rate = mushrooms[-2] - mushrooms[-1]
    for i in range(0, len(mushrooms)-1):
        if mushrooms[i] < rate:
            total += mushrooms[i]
        else:
            total += rate
    return total



f_in = open('A-small-attempt3.in', 'r')
f_out = open('asmall.out', 'w')
cases = int(f_in.readline().rsplit()[0])
for i in range(1, cases+1):
    case = f_in.readline().rsplit()
    mush = f_in.readline().rsplit()
    mush = [int(x) for x in mush]

    # print "case #" + str(i) + ": " + str(get_additional_clapper(audiences))
    f_out.write("case #" + str(i) + ": " + str(case_one(mush)) + " " + str(case_two(mush)))
    if i < cases:
        f_out.write('\n')
f_in.close()
f_out.close()
