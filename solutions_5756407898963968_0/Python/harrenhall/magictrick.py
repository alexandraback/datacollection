#!/usr/bin/python

cases = input()

for case in range(1, cases+1):
    
    print ("Case #" + str(case) + ":"),
    
    ans1 = input() -1
    field1 = []
    for i in range(4):
        line = raw_input().split()
        field1.append(line)

    ans2 = input() -1
    field2 = []
    for i in range(4):
        line = raw_input().split()
        field2.append(line)
        
    hits = [0] * 20
    for i in range(4):
        f = field1[ans1][i]
        hits[int(f)] +=1
        f = field2[ans2][i]
        hits[int(f)] +=1

    twos = 0
    index = 0
    for i in range(20):
        if hits[i] == 2:
            twos +=1
            index = i
            
    if twos == 0:
        print "Volunteer cheated!"
        
    elif twos > 1:
        print "Bad magician!"
        
    else:
        print index
    
