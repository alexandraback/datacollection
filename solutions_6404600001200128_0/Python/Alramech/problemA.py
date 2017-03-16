import math
f = open("A-small-attempt0.in", "r")
#f = open("A-large.in", "r")
#f = open("a1.txt", "r")
num_cases = int(f.readline())
cases = []
for c in range(num_cases):
    cases.append((f.readline(), f.readline()))
    
def processCase(case):
    num_cases = case[0]
    tok = case[1].split()
    plate = [int(x) for x in tok]
    return plate
    
  
    
def processTest(test):
    eaten1 = 0
    eaten2 = 0
    platePrev = test[0]
    minEat = 0
    for plate in test[1:]:
        if plate < platePrev:
            eaten1 += platePrev - plate
            minEat = max(minEat, math.ceil((platePrev - plate)))
        platePrev = plate    
    platePrev = test[0]
    for plate2 in test[:-1]:
        v1 = minEat
        #v2 = platePrev - plate2
        eaten2 += min(v1, plate2)
    #platePrev = test[0]
    return eaten1, eaten2
cnum = 1
g = open("A-out.txt", "w")
#g = open("A-large-out.txt", "w")
#print(cases)
for c in cases:
    print(processCase(c))
    value = processTest(processCase(c))
    print("Case #{}: {} {}".format(cnum, value[0], value[1]))
    g.write("Case #{}: {} {}\n".format(cnum, value[0], value[1]))
    #print(cnum)
    cnum+=1