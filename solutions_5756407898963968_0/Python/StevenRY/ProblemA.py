f = open('A-small-attempt0.in', 'r')
case = f.read()
f.close()
f = open('output.out', 'w')

def solve(op1, op2):
    s1 = []
    s2 = []
    for i in op1:
        s1.append(int(i))
    for i in op2:
        s2.append(int(i))
    s = list(set(s1) & set(s2))
    if len(s) == 0:
        return "Volunteer cheated!\n"
    elif len(s) > 1:
        return "Bad magician!\n"
    else:
        return str(s[0]) + "\n"

status = 0
sp = case.split('\n')
line = 1
line1 = -1
line2 = -1
options1 = []
options2 = []
number = 1

while line < len(sp):
    if status == 0:
        line1 = int(sp[line])
     #   print line1
        status += 1
        line += 1
    elif status == 1:
        temp = line + (line1 - 1)
        options1 = sp[temp].split(' ')
   #     print options1
        line += 4
        status += 1
    elif status == 2:
        line2 = int(sp[line])
    #    print line2
        status += 1
        line += 1
    elif status == 3:
        temp = line + (line2 - 1)
        options2 = sp[temp].split(' ')
   #     print options2
        line += 4
        status = 0
        print "Case #" + str(number) + ": " + solve(options1, options2),
        f.write("Case #" + str(number) + ": " + solve(options1, options2))
        number += 1

f.close()
