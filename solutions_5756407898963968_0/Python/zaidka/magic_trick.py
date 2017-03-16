#! /usr/bin/env python

def solve(file):
    answer1 = int(file.readline()) - 1
    arrangement1 = []
    for _ in range(4):
        arrangement1.append([int(x) for x in file.readline().split(' ')])

    answer2 = int(file.readline()) - 1
    arrangement2 = []
    for _ in range(4):
        arrangement2.append([int(x) for x in file.readline().split(' ')])

    intersection = list(set(arrangement1[answer1]) & set(arrangement2[answer2]))
    if len(intersection) == 1:
        return intersection[0]
    elif len(intersection) == 0:
        return "Volunteer cheated!"
    elif len(intersection) > 1:
        return "Bad magician!"
    else:
        return "Unexpected error!"


input = open('input.txt')
cases = int(input.readline())
output = open('output.txt', 'w')
for i in range(cases):
    res = solve(input)
    output.write("Case #%d: %s\n" % (i + 1, res))
output.close()
input.close()