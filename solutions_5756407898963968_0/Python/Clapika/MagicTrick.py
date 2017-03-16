__author__ = 'Clapika'

fin = open('input', "r+")
fout = open('output', "w")

n = int(fin.readline())

for i in range(n):
    first_try = int(fin.readline())
    first_matrix = [fin.readline().split() for x in range(4)]
    second_try = int(fin.readline())
    second_matrix = [fin.readline().split() for x in range(4)]
    answers = list(set(first_matrix[first_try - 1]).intersection(set(second_matrix[second_try - 1])))
    print(answers)
    if len(answers) == 1:
        fout.write("Case #%d: %s" % (i + 1, answers[0] + "\n"))
    elif len(answers) == 0:
        fout.write("Case #%d: %s" % (i + 1, "Volunteer cheated!\n"))
    else:
        fout.write("Case #%d: %s" % (i + 1, "Bad magician!\n"))