with open("A-small-attempt0.in") as f:
    lines = f.readlines()

lineno = 0
def readline():
    global lineno
    lineno += 1
    return lines[lineno-1]

cases = int(readline())
for case in range(1, cases+1):
    print("Case #"+str(case)+": ", end="")
    row1 = int(readline())-1
    row1 = [readline() for _ in range(4)][row1]
    row2 = int(readline())-1
    row2 = [readline() for _ in range(4)][row2]
    set1 = {int(token) for token in row1.split(" ")}
    set2 = {int(token) for token in row2.split(" ")}
    s = set1.intersection(set2)
#    print(s)
    if len(s) == 0:
        print("Volunteer cheated!")
    elif len(s) > 1:
        print("Bad magician!")
    else:
        for x in s: print(str(x))
        
