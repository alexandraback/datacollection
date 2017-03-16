problem = "A"
case = "small" # "small" "large"

input_file  = "%s-%s.in" % (problem,case)
output_file = "%s-%s.out" % (problem,case)


with open(input_file, 'r') as inputf, open(output_file, 'w') as outputf:
    lines = inputf.readlines()
    N = int(lines.pop(0))
    for i in range(0,N,1):
        # do something
        rows  = int(lines.pop(0))
        words = []
        for j in range(rows):
            words.append(lines.pop(0).strip())
        ars = []
        for w in words:
            prev  = None
            count = 0
            w2 = []
            for l in w:
                if (l==prev):
                    count = count + 1
                elif (prev == None):
                    count = 1
                    prev  = l
                else:
                    w2.append((prev, count))
                    count = 1
                    prev  = l

            w2.append((prev, count))
            ars.append(w2)

        validx = True
        for h in range(1,len(ars), 1):
            print 10, ars[h], ars[0], len(ars[h]) != len(ars[0])
            if (len(ars[h]) != len(ars[0])):
                validx = False
            else:
                for l in range(len(ars[0])):
                    if ars[h][l][0] != ars[0][l][0]:
                        validx = False
        print ars
        print validx
        tot = 0
        if (validx == True):
            for w in range(len(ars[0])):
                nums = [a[w][1] for a in ars]
                maxm = max(nums)
                print nums, maxm
                numss = []
                for j in range(1,maxm + 1):
                    numss.append(sum(map(lambda x: abs(j-x), nums)))
                print tot, numss
                tot = tot + min(numss)
            outputf.write("Case #%s: %s\n" % (i+1, tot))
        else:
            outputf.write("Case #%s: %s\n" % (i+1, "Fegla Won"))
