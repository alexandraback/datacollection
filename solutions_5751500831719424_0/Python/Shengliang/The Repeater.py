def generateDict(s):
    l = len(s)
    pre = ' ';
    key = []
    value = []
    k = -1
    for i in range(l-1):
        if pre == s[i]:
            value[len(value) - 1] += 1
        else:
            k += 1
            key.append(s[i])
            value.append(1)
            pre = s[i]
    return (key, value)

def main():
    fin = file("A-small-attempt1.in","r")
    t = int(fin.readline())
    fout = file("A-small.out", "w")
    for i in range(t):
        scanf = fin.readline()
        n = int(scanf)
        st = []
        for j in range(n):
            st.append(fin.readline())
        dataStr = []
        dataLen = []
        dupliSet = set()
        for s in st:
            key, value = generateDict(s)
            #print key
            #print value
            keyStr = "".join(key)
            #print keyStr
            dupliSet.add(keyStr)
            dataStr.append(keyStr)
            dataLen.append(value)
        if len(dupliSet) > 1:
            output = 'Case #' + str(i+1) + ": Fegla Won\n"
            fout.write(output)
            continue
        counter = 0
        l = len(keyStr)
        for k in range(l):
            counter += abs(dataLen[0][k] - dataLen[1][k])
        output = 'Case #' + str(i+1) + ": " + str(counter) + '\n'
        fout.write(output)

if __name__ == '__main__':
    main()
