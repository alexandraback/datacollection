from __future__ import print_function

f = open('C:\\Users\\djspence\\Downloads\\A-large.in', 'r')
#f = open('C:\\Users\\djspence\\Downloads\\testing.in', 'r')

f2 = open('C:\\Users\\djspence\\Documents\\Miscellaniety\\codejam2016\\senatesoln.txt', 'w')

tries = int(f.readline())

alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
out = ""

for i in range(0, tries):
    out = out + "Case #" + str(i + 1) + ": "
    numParties = int(f.readline())
    partySizes = f.readline().split()
    for q in range(0, len(partySizes)):
        partySizes[q] = int(partySizes[q])
    tot = sum(partySizes)
    
    ps2 = []
    for j in partySizes:
        ps2.append(j)
    ps2.sort()
    ps2.reverse()
    
    mapping = dict()
    
    loc = 0
    
    for j in range(0, len(ps2)):
        if j == 0 or ps2[j] != ps2[j - 1]:
            loc = -1
        while True:
            loc = loc + 1
            if partySizes[loc] == ps2[j]:
                mapping[j] = loc
                break
                
    while tot > 0:
        if ps2[0] > ps2[1]:
            ps2[0] = ps2[0] - 1
            tot = tot - 1
            out = out + alph[mapping[0]] + " "
        else:
            if len(ps2) >= 3 and ps2[0] == 1 and ps2[1] == 1 and ps2[2] == 1:
                ps2[0] = ps2[0] - 1
                tot = tot - 1
                out = out + alph[mapping[0]] + " "
                for swapping in range(1, len(ps2)):
                    if ps2[swapping - 1] < ps2[swapping]:
                        temp = ps2[swapping - 1]
                        ps2[swapping - 1] = ps2[swapping]
                        ps2[swapping] = temp
                        temp = mapping[swapping - 1]
                        mapping[swapping - 1] = mapping[swapping]
                        mapping[swapping] = temp
                    else:
                        break
            ps2[0] = ps2[0] - 1
            ps2[1] = ps2[1] - 1
            tot = tot - 2
            out = out + alph[mapping[0]] + alph[mapping[1]] + " "
            for swapping in range(2, len(ps2)):
                if ps2[swapping - 1] < ps2[swapping]:
                    temp = ps2[swapping - 2]
                    ps2[swapping - 2] = ps2[swapping]
                    ps2[swapping] = temp
                    temp = mapping[swapping - 2]
                    mapping[swapping - 2] = mapping[swapping]
                    mapping[swapping] = temp
                else:
                    break
                    
    out = out + "\n"
    
print(out, file = f2)
f2.close()