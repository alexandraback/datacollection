import math

def main():    
    f = open('A-large.in', 'r')
    numberOfProblems = int(f.readline())
    out = open('A-large.out','w')
    for case in range(0,numberOfProblems):
        N = f.readline()

        m = f.readline()
        m = m.replace("\n","")
        m = m.split(" ")
        m = list(map(int,m))

        prevShrooms = 0
        firstMethod = 0

        secondMethod = 0
        largestGap = 0
        
        for i in m:
            if prevShrooms > i:
                shroomDif = prevShrooms-i
                firstMethod += shroomDif
                if largestGap < shroomDif:
                    largestGap = shroomDif
            prevShrooms = i


        #now loop through again counting how many she ate based on rate of shroom dif
        del(m[-1])
        for i in m:
            if i >= largestGap:
                secondMethod += largestGap
            else:
                secondMethod += i
        
            
            


        answer = str(firstMethod) + " " + str(secondMethod)
        #write answer to out
        out.write("Case #" + str(case+1) + ": " + str(answer) + "\n")



    f.close()
    out.close()



if __name__ == "__main__":
    main()


