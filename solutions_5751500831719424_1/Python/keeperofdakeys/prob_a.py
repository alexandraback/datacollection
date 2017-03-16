#!/usr/bin/env python3

def make_ideal(string):
    ideal = [string[0]]
    ideal_counts = [1]
    for x in xrange(1,len(string)):
        char = string[x]
        if ideal[-1] != char:
            ideal.append(char)
            ideal_counts.append(1)
        else:
            ideal_counts[-1] += 1
    return (ideal, ideal_counts)

count = int(raw_input())
for x in xrange(1,count+1):
    num_strings = int(raw_input())
    strings = []
    for y in xrange(0,num_strings):
        strings.append(raw_input())

    fail = False
    ideals = [make_ideal(strings[0])]
    ideal = ideals[0][0]
    for y in xrange(1, len(strings)):
        ideals.append(make_ideal(strings[y]))
        if ideal != ideals[-1][0]:
            fail = True

    if fail:
        print ("Case #" + str(x) + ": Fegla Won")
        continue
    
    #min_ideal = [1000] * len(ideal)
    #sum_ideal = [0] * len(ideal)
    sep_ideals = []
    for y in xrange(0, len(ideal)):
        sep_ideals.append([])
    for y in xrange(0, len(strings)):
        ideal_ = ideals[y][1]
        for z in xrange(0,len(ideal_)):
            sep_ideals[z].append(ideal_[z])
            #sum_ideal[z] += num
            #if num < min_ideal[z]:
            #    min_ideal[z] = num
    cost = 0
    for y in xrange(0,len(ideal)):
        repeat = True
        while repeat:
            min_count = [100, 0]
            max_count = [0, 0]
            for z in xrange(0, len(strings)):
                num = sep_ideals[y][z]
                if num < min_count[0]:
                    min_count[0] = num
                    min_count[1] = 0
                if num > max_count[0]:
                    max_count[0] = num
                    max_count[1] = 0
            for z in xrange(0, len(strings)):
                num = sep_ideals[y][z]
                if num == min_count[0]:
                    min_count[1] += 1
                elif num == max_count[0]:
                    max_count[1] += 1
            if min_count[0] == max_count[0]:
                repeat = False
            elif min_count[1] < max_count[1]:
                for z in xrange(0, len(strings)):
                    if sep_ideals[y][z] == min_count[0]:
                        sep_ideals[y][z] += 1
                        cost += 1
            elif max_count[1] < min_count[1]:
                for z in xrange(0, len(strings)):
                    if sep_ideals[y][z] == max_count[0]:
                        sep_ideals[y][z] -= 1
                        cost += 1
            else:
                for z in xrange(0, len(strings)):
                    if sep_ideals[y][z] == min_count[0]:
                        sep_ideals[y][z] += 1
                        cost += 1




    print ("Case #" + str(x) + ": " + str(cost))
