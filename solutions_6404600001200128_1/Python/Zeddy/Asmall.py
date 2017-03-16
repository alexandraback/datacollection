if __name__ == "__main__":
    fin = open('A-large.in', 'r')
    fout = open('A-large.out', 'w')

    cases = fin.readline()
    #print cases

    for case_num in range(0, int(cases)):
        num_turns = int(fin.readline())
        line = fin.readline().split(' ')

        mushroom_list = []

        for i in range(0, num_turns):
            mushroom_list.append(int(line[i]))


        sum_dif = 0

        for i in range(1, num_turns):
            if mushroom_list[i] < mushroom_list[i-1]:
                sum_dif += mushroom_list[i-1]-mushroom_list[i]


        max_dif = 0
        mushrooms_eaten = 0

        for i in range(1, num_turns):
            if (mushroom_list[i-1] - mushroom_list[i]) > max_dif:
                max_dif = mushroom_list[i-1] - mushroom_list[i]

        for i in range(0, num_turns-1):
            if mushroom_list[i] > max_dif:
                mushrooms_eaten += max_dif
            else:
                mushrooms_eaten += mushroom_list[i]


        print "Case #" + str(case_num+1) + ": " + str(sum_dif) + ' ' + str(mushrooms_eaten)
        fout.write("Case #" + str(case_num+1) + ": " + str(sum_dif) + ' ' + str(mushrooms_eaten) + "\n")

    fin.close()
    fout.close()