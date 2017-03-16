import sys

def solve(row1,row2):
    count = 0
    for i in range(4):
        for j in range(4):
            if row1[i]==row2[j]:
                count+=1
                num = row1[i]
    if count == 1:
        return num
    elif count >1:
        return "Bad magician!"
    else:
        return "Volunteer cheated!"

numcases = int(sys.stdin.readline())
for casenum in range(1,numcases+1):
    row1_num = int(sys.stdin.readline())
    row1=[]
    for i in range(1,5):
        if (i==row1_num):
            row1=(sys.stdin.readline().strip().split())
        else:
            sys.stdin.readline()
    row2_num = int(sys.stdin.readline())
    row2 = []
    for i in range(1,5):
        if (i==row2_num):
            row2=(sys.stdin.readline().strip().split())
        else:
            sys.stdin.readline()
    print 'Case #' + repr(casenum) + ': ' +solve(row1,row2)

    
