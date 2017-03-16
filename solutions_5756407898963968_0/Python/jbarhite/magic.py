def explode(s, c):
    t = []
    s += c;
    p = 0;
    for i in range(len(s)):
        if (s[i] == c or s[i] == "\n") and s[p:i] != "" and s[p:i] != "\n":
            t.append(s[p:i])
            p = i + 1
    return t

def solveCase(lines):
    for i in range(len(lines)):
        lines[i] = explode(lines[i], " ")
    r1 = int(lines[0][0])
    r2 = int(lines[5][0])
    r1numbers = lines[r1]
    r2numbers = lines[r2+5]
    n = 0
    a = 0
    for i in r1numbers:
        for j in r2numbers:
            if i == j:
                n += 1
                a = i
    if n == 1: return a
    if n > 1: return "Bad magician!"
    return "Volunteer cheated!"

def process(data):
    out = ""
    caseNum = 1
    lines = []
    for i in range(1, len(data)):
        lines.append(data[i])
        if i % 10 == 0:
            if caseNum > 1: out += '\n'
            out += "Case #" + str(caseNum) + ": "
            out += solveCase(lines)
            caseNum += 1
            lines = []
    return out

def main(fn):
    iFile = open(fn + ".in", "r")
    oFile = open(fn + ".out", "w")
    print("Files opened.")

    data = []
    while True:
        line = iFile.readline()
        if not line: break
        data.append(line)

    out = process(data)
    print("Calculations complete. Outputting to file.")
    oFile.writelines(out)
    print("Output complete.")
    iFile.close()
    oFile.close()
    print("Files closed.")

main("small")
