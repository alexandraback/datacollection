infile = open("A-small-attempt2.in", "r")
outfile = open("output.txt", "a")

cases = int(infile.readline())

for i in range(1, cases+1):
    Kaylin_one = 0
    Kaylin_two = 0
    difference = 0
    N = int(infile.readline()[:-1])
    intervals = infile.readline()[:-1].split()
    for j in range(1, len(intervals)):
        if int(intervals[j-1]) > int(intervals[j]):
            Kaylin_one += (int(intervals[j-1]) - int(intervals[j]))
    for h in range(1, len(intervals)):
        if int(intervals[h-1]) > int(intervals[h]) and (int(intervals[h-1]) - int(intervals[h])) > difference:
            difference = int(intervals[h-1]) - int(intervals[h])
    for k in range(1, len(intervals)):
        if int(intervals[k-1]) > int(intervals[k]):
            if (int(intervals[k-1]) - int(intervals[k])) >= difference and int(intervals[k-1]) > difference:
                Kaylin_two += (int(intervals[k-1]) - int(intervals[k]))
            elif (int(intervals[k-1]) - int(intervals[k])) >= difference and int(intervals[k-1]) < difference:
                Kaylin_two += int(intervals[k-1])
            else:
                if int(intervals[k-1]) < difference:
                    Kaylin_two += int(intervals[k-1])
                else:
                    Kaylin_two += difference
        else:
            if int(intervals[k-1]) > difference:
                Kaylin_two += difference
            else:
                Kaylin_two += int(intervals[k-1])

    outfile.write("Case #" + str(i) + ": " + str(Kaylin_one) + " " + str(Kaylin_two) + "\n")

infile.close()
outfile.close()
