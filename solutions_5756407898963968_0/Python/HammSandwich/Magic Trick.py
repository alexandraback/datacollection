#import re #regex
#import math #math
# math.sqrt(x) -> squre root of x
# math.pow(x, y) -> x ^ y
# math.ceil(math.sqrt(a))


inFile = "A-small-attempt0"
def main():
    f = open("C:\Users\Peter\Downloads\\" + inFile + ".in", "r")    
    o = open("C:\Users\Peter\Desktop\\" +inFile + ".out", "w")
    
    
    n = int(f.readline())

    for i in range(n):
        a1 = int(f.readline()[:-1])
        map1 = []
        for j in range(4):
            line = f.readline()[:-1]
            line = [int(l) for l in line.split(" ")]
            if len(line) != 4:
                print "problem"
            map1.append(line)
        a2 = int(f.readline()[:-1])
        map2 = []
        for j in range(4):
            line = f.readline()[:-1]
            line = [int(l) for l in line.split(" ")]
            if len(line) != 4:
                print "problem"
            map2.append(line)
        output(i+1, process(a1, a2, map1, map2), o)
        
def process(a1, a2, map1, map2):
    possible = map1[a1-1]
    round2 = map2[a2-1]
    correct = [x for x in possible if x in round2]
    if len(correct) == 0:
        return "Volunteer cheated!"
    elif len(correct) > 1:
        return "Bad magician!"
    else:
        return correct[0]

    
def stringmap(map):
    out = ""
    for line in map:
        out = out + "\n"
        for item in line:
            out = out + str(item) +" "
        out = out[:-1]
    return out



def output(case, outline, o):
    print "Case #" + str(case) + ": " + str(outline)
    o.write( "Case #" + str(case) + ": " + str(outline) + "\n")
    
if __name__ == "__main__":
    main()