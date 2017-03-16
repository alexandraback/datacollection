__author__ = 'muhammadkhadafi'
import math

def minimum_one_side(trees):
    minimums = []
    for tree in range(0, len(trees)):
        current_min = 1000000000
        for other_tree in range(0, len(trees)):
            if tree == other_tree:
                continue
            in_out = []
            for other_other_tree in range(0, len(trees)):
                if other_other_tree == tree or other_other_tree == other_tree:
                    continue
                position = (trees[other_tree][0]-trees[tree][0])*(trees[other_other_tree][1]-trees[tree][1]) - \
                           (trees[other_tree][1]-trees[tree][1])*(trees[other_other_tree][0]-trees[tree][0])
                # print tree, other_tree, other_other_tree, position
                if position == 0:
                    in_out.append(position)
                elif position < 0:
                    in_out.append(-1)
                else:
                    in_out.append(1)
            io = dict((i, in_out.count(i)) for i in in_out)

            if -1 in io and 1 in io:
                if io[-1] <= io[1]:
                    this_min = io[-1]
                else:
                    this_min = io[1]
            else:
                this_min = 0
            # print this_min
            if current_min > this_min:
                current_min = this_min
        minimums.append(current_min)
    return minimums


f_in = open('C-small-attempt0.in', 'r')
f_out = open('csmall.out', 'w')
cases = int(f_in.readline().rsplit()[0])
for i in range(1, cases+1):
    trees = int(f_in.readline().rsplit()[0])
    trees_arr = []
    for j in range(0, trees):
        trees_i = f_in.readline().rsplit()
        trees_tup = (int(trees_i[0]), int(trees_i[1]))
        trees_arr.append(trees_tup)
    result = minimum_one_side(trees_arr)

    # print "case #" + str(i) + ": " + str(get_additional_clapper(audiences))
    f_out.write("case #" + str(i) + ":")
    f_out.write('\n')
    for res in result:
        if str(res) != "1000000000":
            f_out.write(str(res))
        else:
            f_out.write("0")
        f_out.write('\n')
f_in.close()
f_out.close()