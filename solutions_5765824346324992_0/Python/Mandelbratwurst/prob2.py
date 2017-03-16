import math

def main():    
    f = open('B-small-attempt3.in', 'r')
    numberOfProblems = int(f.readline())
    out = open('B-small-attempt3.out','w')
    for case in range(0,numberOfProblems):
        N = f.readline()
        N = N.replace("\n","")
        N = int(N.split(" ")[1])
        
        

        M = f.readline()
        M = M.replace("\n", "" )
        M = M.split(" ")
        M = list(map(int,M))
        copyM = M[:]

        fullLoop = max(M)
        maxIndex = (len(M)-1) - M[::-1].index(fullLoop)

        answer = 1


        
        count = 0
        while M[maxIndex] > 0:
            M[:] = [x - 1 for x in M]
            for i in range(0,len(M)):
                if M[i] == 0:
                    count += 1
                    if i != maxIndex:
                        M[i] = copyM[i]


        print(count)
        M = copyM[:]
        N = N % count
        print("new n")
        print(N)
        N = N + count + count
        N = N - len(M)
        
    
        while N > 1:
            for i in range(0,len(M)):
                M[i] = M[i] - 1                
                if M[i] == 0:
                    N-=1
                    if N == 0:
                        answer = M.index(min(M))+1
                        break
                    M[i] = copyM[i]
        



        #write answer to out
        out.write("Case #" + str(case+1) + ": " + str(answer) + "\n")



    f.close()
    out.close()



if __name__ == "__main__":
    main()
