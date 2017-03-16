import sys

def main():
    f = open(sys.argv[1], "r")
    t = int(f.readline().strip())

    f2 = open(sys.argv[2], "w")

    for i in range(t):
        f2.write("Case #"+str(i+1)+": ")
        n = int(f.readline().strip())

        sk = []
        stnums = []
        flag = False
        for j in range(n):
            tmpst = f.readline().strip()
            tmpsk = []
            lastch = ""
            tmpstnum = []
            for ch in tmpst:
                if len(lastch) <= 0 or ch != lastch:
                    tmpsk.append(ch)
                    lastch = ch
                    tmpstnum.append(1)
                else:
                    tmpstnum[-1] += 1

            if len(sk) > 0:
                if sk != tmpsk:
                    while j < n-1:
                        tmpline = f.readline()
                        j+=1
                    f2.write("Fegla Won\n")
                    flag = True
                    break
            else:
                sk = tmpsk
            stnums.append(tmpstnum)

        if flag:
            continue

        res = 0
        for j in range(len(stnums[0])):
            tmpm = []
            for k in range(len(stnums)):         
                tmpm.append(stnums[k][j])
            tmpm = sorted(tmpm)
            md = tmpm[int(len(tmpm)/2)]
            for k in range(len(tmpm)):
                res += abs(md-tmpm[k])

        f2.write(str(res))
        
        f2.write("\n")

if __name__ == "__main__":
    main()
    
