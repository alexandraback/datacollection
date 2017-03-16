out = open("Sample_AnswerA.txt", "w")

def get_result(i, answer1, answer2, grid1, grid2):
    print(answer1, answer2)
    relevant_row_in_1 = grid1[answer1]
    print(relevant_row_in_1)
    relevant_row_in_2 = grid2[answer2]
    print(relevant_row_in_2)
    answers = (set(relevant_row_in_1)).intersection(set(relevant_row_in_2))
    print(answers)
    if len(answers) == 1:
        out.write("Case #" + str(i) + ": " + str(list(answers)[0])+"\n")
    elif len(answers) > 1:
        out.write("Case #" + str(i) + ": Bad magician!\n")
    else:
        out.write("Case #" + str(i) + ": Volunteer cheated!\n")

    

file = open("A-small-attempt0.in")
N = int(file.readline())
for i in range(1, N+1):
    answer1 = int(file.readline()) -1
    #Build up the first grid
    grid1 = []
    for j in range(4):
        grid1.append([int(x) for x in file.readline().split()])
    answer2 = int(file.readline()) -1
    grid2 = []
    for j in range(4):
        grid2.append([int(x) for x in file.readline().split()])
    get_result(i, answer1, answer2, grid1, grid2)
out.close()
