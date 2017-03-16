import copy

inp= open('in1.txt', 'r')
inp_list = [x for x in inp.read().split('\n')]
numbrs = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
kk = [[0, 'Z'],[2,'W'],[8,'G'],[6,'X'],[4,'U'],[5,'F'],[7,'S'],[1,'O'],[9,'N'],[3,'T']]

n = int(inp_list.pop(0))
num = set()
f = open("output1.txt", "w")

def to_num(a):
    a = str(a)
    result = set()
    for i in a:
        result.add(i)
    return set(result)

for i in range(n):
    answer = ""
    part = int(inp_list.pop(0))
    sir = list(map(int,inp_list.pop(0).split(" ")))
    frs = 65
    first = 0
    second = 0
    s = sum(sir)
    while(s > 3):
        first = sir.index(max(sir))
        sir[first] -= 1
        second = sir.index(max(sir))
        sir[second] -= 1
        s -= 2
        answer += chr(frs + first) + chr(frs + second) + " "
    if(s == 3):
        first = sir.index(max(sir))
        sir[first] -= 1
        s -=1
        answer += chr(frs + first) + ' '
        first = sir.index(max(sir))
        sir[first] -= 1
        second = sir.index(max(sir))
        sir[second] -= 1
        s -= 2
        answer += chr(frs + first) + chr(frs + second) + " "
    if(s == 2):
        first = sir.index(max(sir))
        sir[first] -= 1
        second = sir.index(max(sir))
        sir[second] -= 1
        s -= 2
        answer += chr(frs + first) + chr(frs + second) + " "
    f.write("Case #" + str(i+1) + ": " + answer + "\n")
inp.close()
f.close()
