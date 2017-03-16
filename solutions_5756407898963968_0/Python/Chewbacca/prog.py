#! /usr/bin/env python3
import sys

inp = open(sys.argv[1],"r")

for test_case in range(1, int(inp.readline())+1):
    rowidx = int(inp.readline())-1;
    row1=[]
    for r in range(4):
        if r==rowidx:
            row1 = list(map(int, inp.readline().split()))
        else:
            inp.readline()
    rowidx = int(inp.readline())-1;
    row2=[]
    for r in range(4):
        if r==rowidx:
            row2 = list(map(int, inp.readline().split()))
        else:
            inp.readline()
    ans=[]
    for r in row1:
        if r in row2:
            ans.append(r)
    if len(ans)==0:
        ans = 'Volunteer cheated!'
    elif len(ans)==1:
        ans = ans[0]
    else:
        ans = 'Bad magician!'
    print("Case #{}: {}".format(test_case, ans))
