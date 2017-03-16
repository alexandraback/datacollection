f = open('/Users/shivamahajan/Desktop/file.txt' , 'r')
ff = open('/Users/shivamahajan/Desktop/output.txt' , 'w')
import os
for q in xrange(int(f.readline().split()[0])):
    config1 = []
    a1 = int(f.readline().split()[0])
    for j in xrange(4):
        l = [int(x) for x in f.readline().split()]
        config1.append(l)
    config2 = []
    a2 = int(f.readline().split()[0])
    for j in xrange(4):
        l = [int(x) for x in f.readline().split()]
        config2.append(l)
    common = 0
    ans = []
    for i in config1[a1-1]:
        if i in config2[a2-1]:
            common += 1
            ans.append(i)
    if common == 1:
        ff.write("Case #" + str(q+1) + ": "+ str(ans[0])+ os.linesep)
    elif common > 1:
        ff.write("Case #" + str(q+1) + ": Bad magician!" + os.linesep)
    else:
        ff.write("Case #" + str(q+1) + ": Volunteer cheated!" + os.linesep)